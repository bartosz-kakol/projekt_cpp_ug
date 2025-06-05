#include "Sheep.h"

Sheep::Sheep(const int id, const int birthTurn)
    : AnimalBase(id, birthTurn)
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