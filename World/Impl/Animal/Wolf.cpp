#include "Wolf.h"

Wolf::Wolf(const int id)
    : AnimalBase(id)
{

}

void Wolf::init()
{
    setSpecies("Wolf");
    setPower(8);
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
}
