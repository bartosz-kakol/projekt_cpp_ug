#include "Grass.h"

Grass::Grass(const int id)
    : PlantBase(id)
{

}

void Grass::init() {
    setSign('T');
}
