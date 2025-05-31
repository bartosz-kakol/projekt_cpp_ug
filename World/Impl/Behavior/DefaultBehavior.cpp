#include "DefaultBehavior.h"

#include <iostream>

void DefaultBehavior::behave(IOrganism& self, IWorld& world)
{
    std::cout << "Domyślne zachowanie" << std::endl;
}
