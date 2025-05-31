cmake_minimum_required(VERSION 3.31)
project(projekt_swiat_bartosz_kakol)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE WORLD_SOURCES
        "${CMAKE_SOURCE_DIR}/World/*.h"
        "${CMAKE_SOURCE_DIR}/World/*.cpp"
)

add_executable(projekt_swiat_bartosz_kakol
        LivingWorld.cpp
        ${WORLD_SOURCES}
)

target_include_directories(projekt_swiat_bartosz_kakol PRIVATE "${CMAKE_SOURCE_DIR}")
