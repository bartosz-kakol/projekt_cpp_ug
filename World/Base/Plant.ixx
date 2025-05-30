export module World.Base.Plant;

import World.Base.Organism;
import World;

export class Plant : public Organism
{
public:
    using Organism::init;

    explicit Plant(const int id) : Organism(id)
    {

    }
};
