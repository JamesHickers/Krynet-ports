#include "KrynetApp.hpp"

KrynetApp::KrynetApp()
    : sciter::window(
        SW_TITLEBAR |
        SW_RESIZEABLE |
        SW_CONTROLS |
        SW_MAIN
    )
{
}

bool KrynetApp::initialize()
{
    // Use software rendering for maximum compatibility.
    if (!SciterSetOption(
        nullptr,
        SCITER_SET_GFX_LAYER,
        GFX_LAYER_SOFTWARE
    ))
    {
        return false;
    }

    // Allow the web application to use socket APIs exposed by Sciter.
    if (!SciterSetOption(
        nullptr,
        SCITER_SET_SCRIPT_RUNTIME_FEATURES,
        ALLOW_SOCKET_IO
    ))
    {
        return false;
    }

    // Let Sciter retrieve and render the actual Krynet web client.
    if (!load_url(KrynetWebURL))
    {
        return false;
    }

    expand();

    return true;
}
