cmake_minimum_required(VERSION 3.31)
project(projekt_swiat_bartosz_kakol)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MODULE_IXX_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.ixx"
)

add_executable(projekt_swiat_bartosz_kakol
        LivingWorld.cpp
)

target_sources(projekt_swiat_bartosz_kakol
        PRIVATE
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES ${MODULE_IXX_FILES}
)

