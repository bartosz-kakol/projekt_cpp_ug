export module World.Impl.Plant.Grass;

import World.Base.Plant;
import World;

export class Grass final : public Plant {
public:
    explicit Grass(const int id) : Plant(id)
    {

    }

    void init() override
    {
        setSign('T');
    }
};
