#include "Sheep.h"

Sheep::Sheep(const int id)
    : AnimalBase(id)
{

}

void Sheep::init()
{
    setSpecies("Sheep");
    setPower(3);
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
}