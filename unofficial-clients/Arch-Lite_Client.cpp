#include <sciter-x.h>
#include <sciter-x-window.hpp>

int main() {
    // Only allow network access
    SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SOCKET_IO);

    sciter::window mainWindow(
        SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN
    );

    mainWindow.load_url(L"https://krynet.ai/web");
    mainWindow.expand();
    mainWindow.run_app();

    return 0;
}
