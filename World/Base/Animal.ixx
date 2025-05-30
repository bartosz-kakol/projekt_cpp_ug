export module World.Base.Animal;

import World.Base.Organism;
import World.Models.Position;

export class Animal : public Organism
{
    Position lastPosition{};

public:
    using Organism::init;

    explicit Animal(const int id) : Organism(id)
    {

    }

    void setPosition(const Position position) override
    {
        this->lastPosition = position;

        Organism::setPosition(position);
    }

    [[nodiscard]] Position getLastPosition() const
    {
        return this->lastPosition;
    }
};
