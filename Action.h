#pragma once

// Deklaracja wstępna
class Organism;
class World;

class Action {
public:
    virtual ~Action();

    virtual void act(Organism& self, World& world) = 0;
};
