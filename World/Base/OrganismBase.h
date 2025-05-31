#pragma once

#include <vector>
#include <string>

#include "Interfaces/IOrganism.h"
#include "World/Models/AncestorHistoryItem.h"

class OrganismBase : public IOrganism {
    int id;
    int power;
    int initiative;
    int liveLength;
    int powerToReproduce;
    Position position;
    char sign;
    std::vector<AncestorHistoryItem> ancestorsHistory;

public:
    explicit OrganismBase(int id);
    OrganismBase(const OrganismBase& other) = default;
    OrganismBase(OrganismBase&& other) noexcept = default;

    virtual void init() = 0;

    int getPower() const override;
    void setPower(int power) override;

    int getInitiative() const override;
    void setInitiative(int initiative) override;

    int getLiveLength() const override;
    void setLiveLength(int liveLength) override;

    int getPowerToReproduce() const override;
    void setPowerToReproduce(int powerToReproduce) override;

    Position getPosition() const override;
    void setPosition(Position position) override;

    char getSign() const override;
    void setSign(char spec) override;

    int getId() const override;
    void setId(int id) override;

    std::vector<AncestorHistoryItem>& getAncestorsHistory();
    void addAncestorHistoryItem(int births, int deaths);

    std::string toString() const override;

    OrganismBase& operator=(const OrganismBase& other);
    OrganismBase& operator=(OrganismBase&& other) noexcept;
};
