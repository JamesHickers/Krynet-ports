#pragma once

class KaiBridge;
class SciterView;

class KrynetApp
{
public:
    KrynetApp();
    ~KrynetApp();

    bool initialize();
    void shutdown();

    SciterView* view() const;

private:
    KaiBridge* kai = nullptr;
    SciterView* sciter = nullptr;
    bool initialized = false;
};
