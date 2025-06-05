#include "Toadstool.h"

Toadstool::Toadstool(const int id)
    : PlantBase(id)
{

}

void Toadstool::init()
{
    setSpecies("Toadstool");
    setInitiative(std::numeric_limits<int>::max() - 1);
    setLiveLength(12);
    setPowerToReproduce(4);
}
