// File: krynet_windows.cpp
#include <sciter-x.h>
#include <sciter-x-window.hpp>

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPWSTR, int nCmdShow)
{
    // Enable only necessary runtime features: network/socket I/O for web client
    SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SOCKET_IO);

    // Create a top-level Sciter window
    sciter::window mainWindow(
        SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN
    );

    // Load the official Krynet web client
    mainWindow.load_url(L"https://krynet.ai/web");

    // Start maximized for a seamless app-like experience
    mainWindow.expand();

    // Run the Sciter event loop
    mainWindow.run_app();

    return 0;
}
