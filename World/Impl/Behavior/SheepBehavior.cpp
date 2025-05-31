#include "SheepBehavior.h"

#include <iostream>

#include "World/Impl/Action/MoveRandomly.h"

void SheepBehavior::behave(IOrganism& self, IWorld& world) {
    std::cout << "Losowy ruch" << std::endl;
    MoveRandomly().act(self, world);
}
