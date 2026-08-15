#include "KaiBridge.hpp"

#include <community/krynet/compat/Compat.hpp>

KaiBridge::KaiBridge()
{
}

KaiBridge::~KaiBridge()
{
    shutdown();
}

bool KaiBridge::initialize()
{
    if (initialized)
        return true;

    if (!Compat::initialize("macos"))
        return false;

    initialized = true;

    return true;
}

void KaiBridge::shutdown()
{
    if (!initialized)
        return;

    Compat::shutdown();

    initialized = false;
}

bool KaiBridge::setOption(
    const std::string& name,
    const std::string& value
)
{
    if (!initialized)
        return false;

    return Compat::setOption(
        name,
        value
    );
}

std::string KaiBridge::platform() const
{
    return "macos";
}

bool KaiBridge::isInitialized() const
{
    return initialized;
}
