module;

export module World.Base.Interfaces.IAction;

import World.Base.Interfaces.IWorld;
import World.Base.Interfaces.IOrganism;

export class IAction {
public:
    virtual ~IAction() = default;

    virtual void act(IOrganism& self, IWorld& world) = 0;
};
