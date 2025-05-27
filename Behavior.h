#pragma once

// Deklaracja wstępna
class World;
class Organism;

class Behavior {
public:
    virtual ~Behavior();

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void behave(Organism& self, World& world) = 0;
};
