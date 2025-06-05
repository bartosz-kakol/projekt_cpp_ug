#include "Wolf.h"

Wolf::Wolf(const int id, const int birthTurn)
    : AnimalBase(id, birthTurn)
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
