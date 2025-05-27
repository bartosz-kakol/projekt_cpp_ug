#pragma once

#include <vector>
#include <map>
#include <typeindex>

#include "Action.h"
#include "Position.h"

class Organism;  // Deklaracja wstępna

class World
{
    int width;
    int height;
    int turn = 0;
    std::vector<std::unique_ptr<Organism>> organisms;
    char separator = '.';
    std::map<std::type_index, std::unique_ptr<Action>> actions;

    bool isPositionOnWorld(int x, int y) const;
    bool isPositionFree(Position position) const;

public:
    World(int width, int height);
    World() : World(6, 6) {};

    int getWidth() const;
    void setWidth(int width);

    int getHeight() const;
    void setHeight(int height);

    int getTurn() const;

    void addOrganism(std::unique_ptr<Organism> organism);
    void removeOrganism(int id);

    void addAction(std::unique_ptr<Action> action);
    void removeAction(const std::type_info& i);
    void invokeAction(const std::type_info& i, Organism& organism);

    std::vector<Position> getVectorOfFreePositionsAround(Position position) const;
    std::vector<Organism*> getOrganismsFromPosition(int x, int y) const;

    void makeTurn();

    void writeWorld(const std::string& fileName);
    void readWorld(std::string fileName);

    std::string toString() const;
};
