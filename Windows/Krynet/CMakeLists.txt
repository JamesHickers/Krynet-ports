cmake_minimum_required(VERSION 3.20)

project(KrynetWindows
    VERSION 1.0.0
    DESCRIPTION "Krynet Community Windows Client"
    LANGUAGES CXX
)

# ============================================================
# Project settings
# ============================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin
)

# ============================================================
# Dependencies
# ============================================================

set(SCITER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/sciter
)

set(KAI_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/kai
)

set(KAI_SOURCE_DIR
    ${KAI_DIR}/compat
)

# ============================================================
# Validate dependencies
# ============================================================

if(NOT EXISTS "${SCITER_DIR}")
    message(FATAL_ERROR
        "Sciter SDK not found.\n"
        "Expected: ${SCITER_DIR}"
    )
endif()

if(NOT EXISTS "${KAI_SOURCE_DIR}")
    message(FATAL_ERROR
        "KAI Compatibility Layer not found.\n"
        "Initialize the Git submodule with:\n"
        "  git submodule update --init --recursive"
    )
endif()

# ============================================================
# Java / JNI
# ============================================================

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

message(STATUS "Java compiler: ${Java_JAVAC_EXECUTABLE}")
message(STATUS "Java runtime:  ${Java_JAVA_EXECUTABLE}")

# ============================================================
# KAI Java source
# ============================================================

file(GLOB_RECURSE KAI_JAVA_SOURCES
    CONFIGURE_DEPENDS
    "${KAI_SOURCE_DIR}/*.java"
)

if(NOT KAI_JAVA_SOURCES)
    message(FATAL_ERROR
        "No KAI Java source files were found in:\n"
        "  ${KAI_SOURCE_DIR}"
    )
endif()

set(KAI_BUILD_DIR
    ${CMAKE_CURRENT_BINARY_DIR}/kai
)

set(KAI_CLASSES_DIR
    ${KAI_BUILD_DIR}/classes
)

set(KAI_COMPILE_STAMP
    ${KAI_BUILD_DIR}/.compiled
)

file(MAKE_DIRECTORY
    ${KAI_CLASSES_DIR}
)

add_custom_command(
    OUTPUT
        ${KAI_COMPILE_STAMP}

    COMMAND
        ${CMAKE_COMMAND}
        -E make_directory
        ${KAI_CLASSES_DIR}

    COMMAND
        ${Java_JAVAC_EXECUTABLE}
        -encoding UTF-8
        -d ${KAI_CLASSES_DIR}
        ${KAI_JAVA_SOURCES}

    COMMAND
        ${CMAKE_COMMAND}
        -E touch
        ${KAI_COMPILE_STAMP}

    DEPENDS
        ${KAI_JAVA_SOURCES}

    COMMENT
        "Compiling KAI Compatibility Layer"
)

add_custom_target(KAI
    DEPENDS
        ${KAI_COMPILE_STAMP}
)

# ============================================================
# Krynet Windows sources
# ============================================================

set(KRYNET_SOURCES
    src/main.cpp
    src/KrynetApp.cpp
    src/KrynetApp.hpp
    src/KaiBridge.cpp
    src/KaiBridge.hpp
)

add_executable(Krynet
    ${KRYNET_SOURCES}
)

# ============================================================
# Include directories
# ============================================================

target_include_directories(Krynet PRIVATE

    # Sciter
    ${SCITER_DIR}/include

    # JNI
    ${JNI_INCLUDE_DIRS}

    # KAI source tree
    ${KAI_SOURCE_DIR}

    # Native project
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ============================================================
# KAI dependency
# ============================================================

add_dependencies(Krynet
    KAI
)

# ============================================================
# Sciter
# ============================================================

if(WIN32)

    set(SCITER_LIBRARY
        ${SCITER_DIR}/bin/windows/x64/sciter-x.lib
    )

    if(NOT EXISTS "${SCITER_LIBRARY}")
        message(FATAL_ERROR
            "Sciter library not found:\n"
            "  ${SCITER_LIBRARY}"
        )
    endif()

    target_link_libraries(Krynet PRIVATE
        ${SCITER_LIBRARY}
    )

endif()

# ============================================================
# Windows configuration
# ============================================================

if(WIN32)

    target_compile_definitions(Krynet PRIVATE
        UNICODE
        _UNICODE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )

    target_link_libraries(Krynet PRIVATE
        user32
        shell32
        ole32
        oleaut32
        version
        ws2_32
    )

endif()

# ============================================================
# Compiler configuration
# ============================================================

if(MSVC)

    target_compile_options(Krynet PRIVATE
        /W4
        /EHsc
        /permissive-
    )

else()

    target_compile_options(Krynet PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

endif()

# ============================================================
# Output
# ============================================================

set_target_properties(Krynet PROPERTIES

    OUTPUT_NAME
        "Krynet"

    RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/bin"
)

# ============================================================
# Build information
# ============================================================

message(STATUS "")
message(STATUS "======================================")
message(STATUS " Krynet Windows")
message(STATUS "======================================")
message(STATUS " Sciter: ${SCITER_DIR}")
message(STATUS " KAI:    ${KAI_DIR}")
message(STATUS " JNI:    ${JNI_INCLUDE_DIRS}")
message(STATUS "======================================")
message(STATUS "")
