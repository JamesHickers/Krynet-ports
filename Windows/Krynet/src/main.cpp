#include "KrynetApp.hpp"

int main()
{
    KrynetApp app;

    if (!app.initialize())
        return 1;

    return app.run_app();
}
