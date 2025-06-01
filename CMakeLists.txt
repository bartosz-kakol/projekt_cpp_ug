cmake_minimum_required(VERSION 3.31)
project(projekt_swiat_bartosz_kakol)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB_RECURSE WORLD_SOURCES
        "${CMAKE_SOURCE_DIR}/World/*.h"
        "${CMAKE_SOURCE_DIR}/World/*.cpp"
)

file(GLOB_RECURSE UI_SOURCES
        "${CMAKE_SOURCE_DIR}/UI/*.h"
        "${CMAKE_SOURCE_DIR}/UI/*.cpp"
        "${CMAKE_SOURCE_DIR}/UI/*.ui"
)

qt_add_executable(projekt_swiat_bartosz_kakol
        LivingWorld.cpp
        Spawner.cpp
        UILogger.cpp
        ${WORLD_SOURCES}
        ${UI_SOURCES}
)
target_link_libraries(projekt_swiat_bartosz_kakol PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)
target_include_directories(projekt_swiat_bartosz_kakol PRIVATE "${CMAKE_SOURCE_DIR}")
