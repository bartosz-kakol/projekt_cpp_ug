#pragma once

#include "OrganismBase.h"

class AnimalBase : public OrganismBase {
    Position lastPosition{};

public:
    using OrganismBase::init;

    explicit AnimalBase(int id, int birthTurn);

    void setPosition(Position position) override;
    Position getLastPosition() const;

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;

    AnimalBase& operator=(const AnimalBase& other);
    AnimalBase& operator=(AnimalBase&& other) noexcept;
};
