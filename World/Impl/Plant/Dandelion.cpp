#include "Dandelion.h"

Dandelion::Dandelion(const int id, const int birthTurn)
    : PlantBase(id, birthTurn)
{
}

void Dandelion::init()
{
    setSpecies("Dandelion");
    setLiveLength(6);
    setPowerToReproduce(2);
}
