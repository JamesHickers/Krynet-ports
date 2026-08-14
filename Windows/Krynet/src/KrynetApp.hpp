#pragma once

#include <sciter-x.h>
#include <sciter-x-window.hpp>

class KrynetApp : public sciter::window
{
public:
    KrynetApp();

    bool initialize();

private:
    static constexpr const wchar_t* KrynetWebURL =
        L"https://krynet.ai/web";
};
