#include "SciterView.hpp"

#import <Cocoa/Cocoa.h>

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
     * Initialize the Sciter macOS view here.
     *
     * The exact API depends on the Sciter SDK version.
     */

    initialized = true;

    return true;
}

void SciterView::shutdown()
{
    if (!initialized)
        return;

    /*
     * Destroy the Sciter native view here.
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
     * Load the URL using the Sciter macOS API.
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
