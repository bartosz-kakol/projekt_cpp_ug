#pragma once

#include "World/Base/Interfaces/IAction.h"

class MoveRandomly final : public IAction {
public:
    void act(IOrganism& self, IWorld& world) override;
};

