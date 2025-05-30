module;

#include <memory>

export module World.Models.OrganismRecord;

import World.Base.Interfaces.IOrganism;
import World.Base.Interfaces.IBehavior;

export struct OrganismRecord
{
    std::unique_ptr<IOrganism> organism;
    std::unique_ptr<IBehavior> behavior;
};
