#include "sciter-x.h"
#include "sciter-x-window.hpp"

int uimain(std::function<int()> run) {
    // Create a window
    sciter::window mainWindow(sciter::window::root, sciter::SIZE{800, 600});
    mainWindow.load_file(L"app.html");
    mainWindow.expand(); // Show the window
    return run();
}
