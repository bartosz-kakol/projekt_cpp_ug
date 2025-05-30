module;

#include <vector>

export module World.Base.Interfaces.IWorld;

import World.Models.Position;
import World.Base.Interfaces.IOrganism;

export class IWorld
{
public:
    virtual ~IWorld() = default;

    [[nodiscard]] virtual std::vector<Position> getVectorOfFreePositionsAround(Position position) const = 0;

    [[nodiscard]] virtual std::vector<IOrganism*> getOrganismsFromPosition(int x, int y) const = 0;
};
