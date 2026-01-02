#include <Ultralight/Ultralight.h>
using namespace ultralight;

int main(int argc, char** argv) {
    Config config;
    config.enable_gpu = true;

    RefPtr<App> app = App::Create(config);
    RefPtr<Window> window = Window::Create(app->renderer(), 800, 600, false, Window::kWindowFlags_Titled);
    window->LoadURL("https://krynet.ai/web");
    app->Run();
    return 0;
}
