#include "Sheep.h"

Sheep::Sheep(const int id)
    : AnimalBase(id)
{

}

void Sheep::init()
{
    setSign('S');
    setPower(3);
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
}