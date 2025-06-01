#include "Spawner.h"

Spawner::Spawner(Creator& creator)
    : creator(creator)
{

}

void Spawner::spawn(const std::string& name, const SpawnSettings settings)
{
    mappings[name](settings);
}

std::vector<std::string> Spawner::getAvailableOrganismNames() const
{
    std::vector<std::string> names;
    names.reserve(mappings.size());

    for (const auto& [name, _] : mappings) {
        names.push_back(name);
    }

    return names;
}
