#include "Grass.h"

Grass::Grass(const int id)
    : PlantBase(id)
{

}

void Grass::init() {
    setSpecies("Grass");
    setLiveLength(6);
    setPowerToReproduce(3);
}
