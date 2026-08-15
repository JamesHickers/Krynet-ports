#include "SciterView.hpp"

#include <TargetConditionals.h>

#if TARGET_OS_IOS

#import <UIKit/UIKit.h>
#include <sciter-x.h>
#include <sciter-x-window.hpp>

#endif

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

#if !TARGET_OS_IOS

    return false;

#else

    /*
     * Initialize the actual Sciter iOS view here.
     *
     * nativeView owns the native Sciter view reference.
     */

    initialized = true;
    return true;

#endif
}

void SciterView::shutdown()
{
    if (!initialized)
        return;

#if TARGET_OS_IOS

    /*
     * Destroy the native Sciter view using
     * the Sciter SDK's iOS API.
     */

#endif

    nativeView = nullptr;
    initialized = false;
}

bool SciterView::loadUrl(const std::string& url)
{
    if (!initialized || url.empty())
        return false;

#if TARGET_OS_IOS

    /*
     * Load the URL using the actual Sciter iOS API.
     */

    return true;

#else

    return false;

#endif
}

bool SciterView::isInitialized() const
{
    return initialized;
}
