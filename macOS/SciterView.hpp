#pragma once

#include <string>

class SciterView
{
public:
    SciterView();
    ~SciterView();

    bool initialize();
    void shutdown();

    bool loadUrl(
        const std::string& url
    );

    bool isInitialized() const;

    void* nativeView() const;

private:
    void* view = nullptr;
    bool initialized = false;
};
