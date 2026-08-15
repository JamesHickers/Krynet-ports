#include "KrynetApp.hpp"

#include "KaiBridge.hpp"
#include "SciterView.hpp"

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
        shutdown();
        return false;
    }

    if (!kai->setOption("platform", "ios"))
    {
        shutdown();
        return false;
    }

    if (!kai->setOption("graphics", "auto"))
    {
        shutdown();
        return false;
    }

    if (!kai->setOption("network", "native"))
    {
        shutdown();
        return false;
    }

    sciter = new SciterView();

    if (!sciter->initialize())
    {
        shutdown();
        return false;
    }

    if (!sciter->loadUrl("https://krynet.ai/web"))
    {
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
