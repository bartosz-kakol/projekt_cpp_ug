#include "Toadstool.h"

Toadstool::Toadstool(const int id, const int birthTurn)
    : PlantBase(id, birthTurn)
{

}

void Toadstool::init()
{
    setSpecies("Toadstool");
    setInitiative(std::numeric_limits<int>::max() - 1);
    setLiveLength(12);
    setPowerToReproduce(4);
}
