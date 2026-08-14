#pragma once

#include <string>

class KaiBridge
{
public:
    bool initialize();
    void shutdown();

    bool setOption(
        const std::string& name,
        const std::string& value
    );

    std::string platform() const;

private:
    bool initialized = false;
};
