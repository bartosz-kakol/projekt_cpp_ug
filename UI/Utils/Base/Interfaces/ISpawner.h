#pragma once

#include "UI/Utils/Models/SpawnSettings.h"

class ISpawner
{
public:
    virtual ~ISpawner() = default;

    virtual void spawn(const std::string& name, SpawnSettings settings) = 0;

    virtual std::vector<std::string> getAvailableOrganismNames() const = 0;
};
