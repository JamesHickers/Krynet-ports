#include "KaiBridge.hpp"

#include <cstdlib>

bool KaiBridge::initialize()
{
    if (initialized)
        return true;

    /*
     * KAI Compat is Java-based.
     *
     * The production implementation initializes the JVM and
     * resolves the KAI Compat entry points through JNI.
     */

    initialized = true;
    return true;
}

void KaiBridge::shutdown()
{
    if (!initialized)
        return;

    initialized = false;
}

bool KaiBridge::setOption(
    const std::string& name,
    const std::string& value
)
{
    if (!initialized)
        return false;

    /*
     * Forward the option to:
     *
     * community.krynet.compat.Krynet
     */

    return true;
}

std::string KaiBridge::platform() const
{
#ifdef _WIN32
    return "windows";
#elif defined(__APPLE__)
    return "macos";
#elif defined(__linux__)
    return "linux";
#else
    return "unknown";
#endif
}
