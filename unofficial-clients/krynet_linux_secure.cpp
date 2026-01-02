// File: krynet_linux_secure.cpp
//OS buntu / Tails / Whonix / PureOS / Kodachi
#include <sciter-x.h>
#include <sciter-x-window.hpp>

int main() {
    // Only enable network/socket access: privacy first
    SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SOCKET_IO);

    // Create a standard top-level Sciter window
    sciter::window mainWindow(
        SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN
    );

    // Load the official Krynet web client
    mainWindow.load_url(L"https://krynet.ai/web");

    // Maximize window for “native client” feel
    mainWindow.expand();

    // Run event loop
    mainWindow.run_app();

    return 0;
}
