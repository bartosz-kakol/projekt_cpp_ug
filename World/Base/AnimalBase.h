#pragma once

#include "OrganismBase.h"

class AnimalBase : public OrganismBase {
    Position lastPosition{};

public:
    using OrganismBase::init;

    explicit AnimalBase(const int id) : OrganismBase(id)
    {

    }

    void setPosition(Position position) override;

    Position getLastPosition() const;
};
