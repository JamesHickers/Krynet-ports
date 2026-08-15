cmake_minimum_required(VERSION 3.22.1)

project(krynet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(KAI_ROOT
    ${CMAKE_CURRENT_LIST_DIR}/../../../../../dependencies/kai
)

add_library(
    krynet
    SHARED

    KrynetApp.cpp
    KaiBridge.cpp
    SciterView.cpp
)

target_include_directories(
    krynet
    PRIVATE

    ${KAI_ROOT}
)

find_library(
    log-lib
    log
)

find_library(
    android-lib
    android
)

find_library(
    dl-lib
    dl
)

target_link_libraries(
    krynet

    ${log-lib}
    ${android-lib}
    ${dl-lib}
)
