module;

#include <iostream>

export module World.Impl.Behavior.SheepBehavior;

import World.Base.Interfaces.IBehavior;
import World.Base.Interfaces.IOrganism;
import World.Base.Interfaces.IWorld;
import World.Impl.Action.MoveRandomly;

export class SheepBehavior final : public IBehavior
{
    void behave(IOrganism& self, IWorld& world) override
    {
        std::cout << "Losowy ruch" << std::endl;
        MoveRandomly().act(self, world);
    }
};
