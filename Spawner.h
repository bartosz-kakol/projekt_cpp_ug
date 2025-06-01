#pragma once

#include <functional>
#include <unordered_map>

#include "UI/Utils/Base/Interfaces/ISpawner.h"
#include "World/Creator.h"

class Spawner final : public ISpawner {
    Creator& creator;
    std::unordered_map<std::string, std::function<void(SpawnSettings)>> mappings;

public:
    explicit Spawner(Creator& creator);

    void spawn(const std::string& name, SpawnSettings settings) override;

    std::vector<std::string> getAvailableOrganismNames() const override;

    template<typename OrganismT, typename BehaviorT>
    void map(const std::string& name);
};

#include "Spawner.tpp"
