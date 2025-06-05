#include "AnimalBase.h"

AnimalBase::AnimalBase(const int id, const int birthTurn)
    : OrganismBase(id, birthTurn)
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

AnimalBase& AnimalBase::operator=(const AnimalBase& other)
{
    if (this != &other) {
        OrganismBase::operator=(other);
        lastPosition = other.getPosition();
    }

    return *this;
}

AnimalBase& AnimalBase::operator=(AnimalBase&& other) noexcept
{
    if (this != &other) {
        OrganismBase::operator=(std::move(other));
        lastPosition = std::move(other.getPosition());
    }

    return *this;
}
