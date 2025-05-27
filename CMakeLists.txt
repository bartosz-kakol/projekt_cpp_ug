cmake_minimum_required(VERSION 3.31)
project(projekt_swiat_bartosz_kakol)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projekt_swiat_bartosz_kakol
        Animal.cpp
        Animal.h
        LivingWorld.cpp
        Organism.cpp
        Organism.h
        Plant.cpp
        Plant.h
        Position.cpp
        Position.h
        World.cpp
        World.h
        PlantImpl/Grass.h
        PlantImpl/Grass.cpp
        AnimalImpl/Sheep.h
        AnimalImpl/Sheep.cpp
        Behavior.cpp
        Behavior.h
        Action.cpp
        Action.h
        ActionImpl/MoveRandomly.cpp
        ActionImpl/MoveRandomly.h)
