#pragma once

#include <string>

class KaiBridge
{
public:
    KaiBridge();
    ~KaiBridge();

    bool initialize();
    void shutdown();

    bool setOption(
        const std::string& name,
        const std::string& value
    );

    std::string platform() const;

    bool isInitialized() const;

private:
    bool initialized = false;
};
