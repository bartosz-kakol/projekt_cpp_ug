export module World.Impl.Animal.Sheep;

import World.Base.Interfaces.IBehavior;
import World.Base.Interfaces.IWorld;
import World.Base.Interfaces.IOrganism;
import World.Base.Animal;
import World.Impl.Action.MoveRandomly;

export class Sheep final : public Animal {
public:
    explicit Sheep(const int id) : Animal(id)
    {

    }

    void init() override
    {
        setSign('S');
        setPower(3);
        setInitiative(3);
        setLiveLength(10);
        setPowerToReproduce(6);
    }
};
