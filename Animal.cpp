#include "Animal.h"

void Animal::move(const int dx, const int dy)
{
    lastPosition = getPosition();

    Organism::move(dx, dy);
}

void Animal::behave(World& world)
{
    behavior->behave(*this, world);

    // Domyślna rutyna behave() będzie zawsze uruchomiona po tym jak konkretne zwierzę wykona swoją własną.
    Organism::behave(world);
}

Position Animal::getLastPosition() const
{
    return lastPosition;
}
