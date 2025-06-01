#include "OrganismBase.h"

OrganismBase::OrganismBase(const int id)
    : id(id),
      power(0),
      initiative(0),
      liveLength(-1),
      powerToReproduce(0),
      species("Unknown")
{}

int OrganismBase::getPower() const {
    return this->power;
}

void OrganismBase::setPower(const int power) {
    this->power = power;
}

int OrganismBase::getInitiative() const {
    return this->initiative;
}

void OrganismBase::setInitiative(const int initiative) {
    this->initiative = initiative;
}

int OrganismBase::getLiveLength() const {
    return this->liveLength;
}

void OrganismBase::setLiveLength(const int liveLength) {
    this->liveLength = liveLength;
}

int OrganismBase::getPowerToReproduce() const {
    return this->powerToReproduce;
}

void OrganismBase::setPowerToReproduce(const int powerToReproduce) {
    this->powerToReproduce = powerToReproduce;
}

Position OrganismBase::getPosition() const {
    return this->position;
}

void OrganismBase::setPosition(const Position position) {
    this->position = position;
}

std::string OrganismBase::getSpecies() const
{
    return this->species;
}

void OrganismBase::setSpecies(const std::string& species)
{
    this->species = species;
}

int OrganismBase::getId() const {
    return this->id;
}

void OrganismBase::setId(const int id) {
    this->id = id;
}

bool OrganismBase::canReproduce() const
{
    return power >= powerToReproduce;
}

std::vector<AncestorHistoryItem>& OrganismBase::getAncestorsHistory() {
    return this->ancestorsHistory;
}

void OrganismBase::addAncestorHistoryItem(const int births, const int deaths) {
    this->ancestorsHistory.emplace_back(AncestorHistoryItem{births, deaths});
}

std::string OrganismBase::toString() const {
    return this->getSpecies() + std::to_string(this->getId());
}

OrganismBase& OrganismBase::operator=(const OrganismBase& other) {
    if (this != &other) {
        id = other.id;
        power = other.power;
        initiative = other.initiative;
        liveLength = other.liveLength;
        powerToReproduce = other.powerToReproduce;
        position = other.position;
        species = other.species;
        ancestorsHistory = other.ancestorsHistory;
    }
    return *this;
}

OrganismBase& OrganismBase::operator=(OrganismBase&& other) noexcept {
    if (this != &other) {
        id = other.id;
        power = other.power;
        initiative = other.initiative;
        liveLength = other.liveLength;
        powerToReproduce = other.powerToReproduce;
        position = other.position;
        species = other.species;
        ancestorsHistory = std::move(other.ancestorsHistory);
    }
    return *this;
}
