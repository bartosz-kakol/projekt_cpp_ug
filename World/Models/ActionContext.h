#pragma once

#include "World/Base/Interfaces/IWorld.h"
#include "World/Base/Interfaces/IOrganism.h"

struct ActionContext {
    IWorld& world;
    IOrganism* organism;
};
