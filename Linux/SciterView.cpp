#include "SciterView.hpp"

#include <sciter-x.h>
#include <sciter-x-window.hpp>

#include <iostream>

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
     * Configure Sciter before creating the window.
     */
    if (!SciterSetOption(
        nullptr,
        SCITER_SET_GFX_LAYER,
        GFX_LAYER_AUTO
    ))
    {
        std::cerr
            << "Sciter: failed to configure graphics\n";

        return false;
    }

    initialized = true;

    return true;
}

void SciterView::shutdown()
{
    if (!initialized)
        return;

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
     * The actual Sciter window is created by
     * the Linux application entry point.
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
