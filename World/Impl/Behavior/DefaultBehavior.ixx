module;

#include <iostream>

export module World.Impl.Behavior.DefaultBehavior;

import World.Base.Interfaces.IBehavior;
import World.Base.Interfaces.IOrganism;
import World.Base.Interfaces.IWorld;

export class DefaultBehavior final : public IBehavior
{
    void behave(IOrganism& self, IWorld& world) override
    {
        std::cout << "Domyślne zachowanie" << std::endl;
    }
};
