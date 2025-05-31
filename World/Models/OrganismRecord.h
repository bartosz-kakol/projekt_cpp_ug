#pragma once

#include <memory>

class IOrganism;
class IBehavior;

struct OrganismRecord {
    std::unique_ptr<IOrganism> organism;
    std::unique_ptr<IBehavior> behavior;
};
