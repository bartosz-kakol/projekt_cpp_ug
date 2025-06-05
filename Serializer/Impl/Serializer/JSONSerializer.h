#pragma once

#include "Serializer/Base/Interfaces/ISerializer.h"
#include "Serializer/vendor/nlohmann/json.hpp"

class JSONSerializer final : public ISerializer {
    static nlohmann::json convertVariantToJson(Variant& variant);
    static Variant convertJsonToVariant(const nlohmann::json& json);

public:
    JSONSerializer();

    void dump(std::ofstream& out, ISerializable* object) const override;

    void load(std::ifstream& in, ISerializable* object) const override;
};
