#include <sciter-x.h>
#include <sciter-x-window.hpp>

#include "KrynetApp.hpp"

class KrynetWindow :
    public sciter::window
{
public:
    KrynetWindow()
        : sciter::window(
            SW_TITLEBAR |
            SW_RESIZEABLE |
            SW_CONTROLS |
            SW_MAIN
        )
    {
    }

    bool initialize()
    {
        if (!SciterSetOption(
            nullptr,
            SCITER_SET_GFX_LAYER,
            GFX_LAYER_AUTO
        ))
        {
            return false;
        }

        if (!SciterSetOption(
            nullptr,
            SCITER_SET_SCRIPT_RUNTIME_FEATURES,
            ALLOW_SOCKET_IO
        ))
        {
            return false;
        }

        if (!load_url(
            WSTR("https://krynet.ai/web")
        ))
        {
            return false;
        }

        expand();

        return true;
    }
};

int main()
{
    KrynetApp krynet;

    if (!krynet.initialize())
        return 1;

    KrynetWindow window;

    if (!window.initialize())
    {
        krynet.shutdown();
        return 1;
    }

    const int result =
        window.run_app();

    krynet.shutdown();

    return result;
}
