#pragma once

#include "World/Base/Interfaces/IOrganism.h";
#include "World/Base/Interfaces/IWorld.h";

class IAction {
public:
    virtual ~IAction() = default;

    virtual void act(IOrganism& self, IWorld& world) = 0;
};

