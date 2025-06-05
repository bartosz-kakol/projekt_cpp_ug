#include "AnimalBase.h"

AnimalBase::AnimalBase(const int id)
    : OrganismBase(id)
{

}

void AnimalBase::setPosition(const Position position)
{
    this->lastPosition = this->getPosition();

    OrganismBase::setPosition(position);
}

Position AnimalBase::getLastPosition() const {
    return this->lastPosition;
}

void AnimalBase::serialize(Variant& v)
{
    OrganismBase::serialize(v);

    v.addChild("lastPosition");
    lastPosition.serialize(v.getChild("lastPosition"));
}

void AnimalBase::deserialize(Variant& source)
{
    OrganismBase::deserialize(source);

    lastPosition = Position();
    lastPosition.deserialize(source.getChild("lastPosition"));
}
