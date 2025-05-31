#pragma once

class IOrganism;
class IWorld;

class IBehavior {
public:
    virtual ~IBehavior() = default;

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void behave(IOrganism& self, IWorld& world) = 0;
};
