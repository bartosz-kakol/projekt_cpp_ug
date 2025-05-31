#include "AnimalBase.h"

void AnimalBase::setPosition(const Position position)
{
    this->lastPosition = position;

    OrganismBase::setPosition(position);
}

Position AnimalBase::getLastPosition() const {
    return this->lastPosition;
}
