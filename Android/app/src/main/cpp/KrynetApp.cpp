#include "KrynetApp.hpp"

#include "KaiBridge.hpp"
#include "SciterView.hpp"

#include <jni.h>
#include <android/log.h>

#define KRYNET_LOG_TAG "Krynet"

#define KRYNET_LOG_ERROR(...) \
    __android_log_print( \
        ANDROID_LOG_ERROR, \
        KRYNET_LOG_TAG, \
        __VA_ARGS__ \
    )

static KrynetApp* g_krynet = nullptr;

KrynetApp::KrynetApp()
{
}

KrynetApp::~KrynetApp()
{
    shutdown();
}

bool KrynetApp::initialize()
{
    if (initialized)
        return true;

    kai = new KaiBridge();

    if (!kai->initialize())
    {
        KRYNET_LOG_ERROR(
            "Failed to initialize KAI"
        );

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "platform",
        "android"
    ))
    {
        KRYNET_LOG_ERROR(
            "Failed to configure Android platform"
        );

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "graphics",
        "auto"
    ))
    {
        KRYNET_LOG_ERROR(
            "Failed to configure graphics"
        );

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "network",
        "native"
    ))
    {
        KRYNET_LOG_ERROR(
            "Failed to configure networking"
        );

        shutdown();
        return false;
    }

    sciter = new SciterView();

    if (!sciter->initialize())
    {
        KRYNET_LOG_ERROR(
            "Failed to initialize Sciter"
        );

        shutdown();
        return false;
    }

    if (!sciter->loadUrl(
        "https://krynet.ai/web"
    ))
    {
        KRYNET_LOG_ERROR(
            "Failed to load Krynet web client"
        );

        shutdown();
        return false;
    }

    initialized = true;

    return true;
}

void KrynetApp::shutdown()
{
    if (sciter)
    {
        sciter->shutdown();

        delete sciter;
        sciter = nullptr;
    }

    if (kai)
    {
        kai->shutdown();

        delete kai;
        kai = nullptr;
    }

    initialized = false;
}

SciterView* KrynetApp::view() const
{
    return sciter;
}

/*
 * Android JNI
 *
 * Java:
 *
 * community.krynet.ports.MainActivity
 *
 * Native:
 *
 * KrynetApp
 */

extern "C"
JNIEXPORT jobject JNICALL
Java_community_krynet_ports_MainActivity_createKrynetView(
    JNIEnv* env,
    jobject activity
)
{
    if (g_krynet)
    {
        KRYNET_LOG_ERROR(
            "Krynet is already initialized"
        );

        return nullptr;
    }

    g_krynet = new KrynetApp();

    if (!g_krynet->initialize())
    {
        KRYNET_LOG_ERROR(
            "Krynet initialization failed"
        );

        delete g_krynet;
        g_krynet = nullptr;

        return nullptr;
    }

    SciterView* sciter =
        g_krynet->view();

    if (!sciter)
    {
        KRYNET_LOG_ERROR(
            "Krynet has no Sciter view"
        );

        g_krynet->shutdown();

        delete g_krynet;
        g_krynet = nullptr;

        return nullptr;
    }

    /*
     * Sciter's Android SDK should expose the
     * native Android View/JNI object here.
     *
     * The exact call depends on the Sciter SDK
     * version being used.
     */

    jobject androidView =
        sciter->androidView(env);

    if (!androidView)
    {
        KRYNET_LOG_ERROR(
            "Sciter failed to provide Android view"
        );

        g_krynet->shutdown();

        delete g_krynet;
        g_krynet = nullptr;

        return nullptr;
    }

    return androidView;
}

extern "C"
JNIEXPORT void JNICALL
Java_community_krynet_ports_MainActivity_destroyKrynet(
    JNIEnv* env,
    jobject activity
)
{
    if (!g_krynet)
        return;

    g_krynet->shutdown();

    delete g_krynet;
    g_krynet = nullptr;
}
