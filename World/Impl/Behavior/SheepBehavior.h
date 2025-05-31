#pragma once

#include "World/Base/Interfaces/IBehavior.h"

class SheepBehavior final : public IBehavior
{
    void behave(IOrganism& self, IWorld& world) override;
};
