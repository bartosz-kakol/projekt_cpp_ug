#include "Grass.h"

Grass::Grass(const int id, const int birthTurn)
    : PlantBase(id, birthTurn)
{

}

void Grass::init() {
    setSpecies("Grass");
    setLiveLength(6);
    setPowerToReproduce(3);
}
