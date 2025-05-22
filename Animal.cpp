#include "Animal.h"

void Animal::move(const int dx, const int dy)
{
    lastPosition = getPosition();

    Organism::move(dx, dy);
}

void Animal::behave(World& world)
{
    // Domyślna rutyna behave() będzie zawsze uruchomiona pierwsza, przed zachowaniem konkretnego zwierzęcia.
    Organism::behave(world);

    return behavior->act(*this, world);
}

Position Animal::getLastPosition() const
{
    return lastPosition;
}
