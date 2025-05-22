#pragma once

// Deklaracja wstępna
class World;
class Organism;

class Behavior {
public:
    // Behavior();
    virtual ~Behavior();

    /// Definiuje zachowanie organizmu gdy nadejdzie jego tura.
    virtual void act(Organism& self, World& world) = 0;
};
