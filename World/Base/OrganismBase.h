#pragma once

#include <vector>
#include <string>

#include "World/Base/Interfaces/IOrganism.h"
#include "World/Models/AncestorHistoryItem.h"

class OrganismBase : public IOrganism {
    int id;
    int birthTurn;
    int power;
    int initiative;
    int liveLength;
    int powerToReproduce;
    Position position;
    std::string species;
    std::vector<AncestorHistoryItem> ancestorsHistory;
    std::vector<IOrganism*> children;

public:
    explicit OrganismBase(int id, int birthTurn);
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

    std::string getSpecies() const override;
    void setSpecies(const std::string& species) override;

    int getId() const override;
    void setId(int id) override;

    bool canReproduce() const override;

    std::vector<AncestorHistoryItem>& getAncestorsHistory() override;
    void addAncestorHistoryItem(int id, int birthTurn, int deathTurn) override;

    std::string toString() const override;

    std::vector<IOrganism*>& getChildren() override;
    void addChild(IOrganism* child) override;

    void notifyChildrenAboutAncestorDeath(int deathTurn) override;

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;

    OrganismBase& operator=(const OrganismBase& other);
    OrganismBase& operator=(OrganismBase&& other) noexcept;
};
