#include "Dandelion.h"

Dandelion::Dandelion(const int id)
    : PlantBase(id)
{
}

void Dandelion::init()
{
    setSpecies("Dandelion");
    setLiveLength(6);
    setPowerToReproduce(2);
}
