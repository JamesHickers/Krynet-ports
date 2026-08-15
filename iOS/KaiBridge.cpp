#include "KaiBridge.hpp"

#include <TargetConditionals.h>

// Adjust this include to the actual public KAI header
// exposed by the compatibility-layer repository.
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

#if TARGET_OS_IOS

    if (!Compat::initialize("ios"))
        return false;

#else

    if (!Compat::initialize())
        return false;

#endif

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

    return Compat::setOption(name, value);
}

std::string KaiBridge::platform() const
{
#if TARGET_OS_IOS
    return "ios";
#else
    return "unknown";
#endif
}

bool KaiBridge::isInitialized() const
{
    return initialized;
}
