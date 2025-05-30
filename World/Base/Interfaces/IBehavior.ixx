export module World.Base.Interfaces.IBehavior;

import World.Base.Interfaces.IWorld;
import World.Base.Interfaces.IOrganism;

export class IBehavior {
public:
    virtual ~IBehavior() = default;

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void behave(IOrganism& self, IWorld& world) = 0;
};
