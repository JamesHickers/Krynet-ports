#pragma once

#include <string>

class SciterView
{
public:
    SciterView();
    ~SciterView();

    bool initialize();
    void shutdown();

    bool loadUrl(const std::string& url);

    bool isInitialized() const;

private:
    bool initialized = false;
    void* nativeView = nullptr;
};
