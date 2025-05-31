#include "OrganismBase.h"

OrganismBase::OrganismBase(const int id)
    : id(id),
      power(0),
      initiative(0),
      liveLength(-1),
      powerToReproduce(0),
      sign('_')
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

char OrganismBase::getSign() const {
    return this->sign;
}

void OrganismBase::setSign(const char spec) {
    this->sign = spec;
}

int OrganismBase::getId() const {
    return this->id;
}

void OrganismBase::setId(const int id) {
    this->id = id;
}

std::vector<AncestorHistoryItem>& OrganismBase::getAncestorsHistory() {
    return this->ancestorsHistory;
}

void OrganismBase::addAncestorHistoryItem(int births, int deaths) {
    const AncestorHistoryItem item{births, deaths};
    this->ancestorsHistory.push_back(item);
}

std::string OrganismBase::toString() const {
    return "{ species: " + std::string(1, this->getSign()) +
        ", power: " + std::to_string(getPower()) +
        ", position: " + getPosition().toString() + "}";
}

OrganismBase& OrganismBase::operator=(const OrganismBase& other) {
    if (this != &other) {
        power = other.power;
        position = other.position;
        sign = other.sign;
        ancestorsHistory = other.ancestorsHistory;
    }
    return *this;
}

OrganismBase& OrganismBase::operator=(OrganismBase&& other) noexcept {
    if (this != &other) {
        power = other.power;
        position = other.position;
        sign = other.sign;
        ancestorsHistory = std::move(other.ancestorsHistory);
    }
    return *this;
}
