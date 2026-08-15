cmake_minimum_required(VERSION 3.20)

project(KrynetLinux
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(KAI_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/kai
)

set(SCITER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/sciter
)

add_executable(Krynet

    main.cpp

    KrynetApp.cpp
    KrynetApp.hpp

    KaiBridge.cpp
    KaiBridge.hpp

    SciterView.cpp
    SciterView.hpp
)

target_include_directories(Krynet
    PRIVATE

    ${KAI_DIR}

    ${SCITER_DIR}
)

target_compile_options(Krynet
    PRIVATE

    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(Krynet
    PRIVATE

    ${SCITER_DIR}/libsciter-gtk.so

    dl
    pthread
)
