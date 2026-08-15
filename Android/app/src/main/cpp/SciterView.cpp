#include "SciterView.hpp"

#include <android/log.h>

#define LOG_TAG "Krynet"

#define LOG_ERROR(...) \
    __android_log_print( \
        ANDROID_LOG_ERROR, \
        LOG_TAG, \
        __VA_ARGS__ \
    )

SciterView::SciterView()
{
}

SciterView::~SciterView()
{
    shutdown();
}

bool SciterView::initialize()
{
    if (initialized)
        return true;

    /*
     * Initialize the Android Sciter view here.
     *
     * The exact implementation depends on the
     * Sciter Android SDK being used.
     */

    initialized = true;

    return true;
}

void SciterView::shutdown()
{
    if (!initialized)
        return;

    /*
     * Destroy the Sciter Android view here.
     */

    view = nullptr;
    initialized = false;
}

bool SciterView::loadUrl(
    const std::string& url
)
{
    if (!initialized)
        return false;

    if (url.empty())
        return false;

    /*
     * Use the Sciter Android API here.
     */

    return true;
}

bool SciterView::isInitialized() const
{
    return initialized;
}

void* SciterView::nativeView() const
{
    return view;
}
