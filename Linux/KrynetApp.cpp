#include "KrynetApp.hpp"

#include "KaiBridge.hpp"
#include "SciterView.hpp"

#include <iostream>

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
        std::cerr
            << "Krynet: failed to initialize KAI\n";

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "platform",
        "linux"
    ))
    {
        std::cerr
            << "Krynet: failed to configure platform\n";

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "graphics",
        "auto"
    ))
    {
        std::cerr
            << "Krynet: failed to configure graphics\n";

        shutdown();
        return false;
    }

    if (!kai->setOption(
        "network",
        "native"
    ))
    {
        std::cerr
            << "Krynet: failed to configure networking\n";

        shutdown();
        return false;
    }

    sciter = new SciterView();

    if (!sciter->initialize())
    {
        std::cerr
            << "Krynet: failed to initialize Sciter\n";

        shutdown();
        return false;
    }

    if (!sciter->loadUrl(
        "https://krynet.ai/web"
    ))
    {
        std::cerr
            << "Krynet: failed to load Krynet web client\n";

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
