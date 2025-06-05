#include "JSONSerializer.h"

#include "Serializer/Base/Interfaces/ISerializable.h"

nlohmann::json JSONSerializer::convertVariantToJson(Variant& variant) // NOLINT(*-no-recursion)
{
    switch (variant.getType())
    {
        case VariantType::Special:
            switch (variant.getValueAs<SpecialVariantValue>())
            {
                case SpecialVariantValue::Object:
                    {
                        nlohmann::json obj;

                        const auto& children = variant.getChildren();

                        for (auto [key, child] : children) {
                            obj[key] = convertVariantToJson(child);
                        }

                        return obj;
                    }
                case SpecialVariantValue::Sequential:
                    {
                        nlohmann::json obj;

                        auto children = variant.getSequentialChildren();

                        for (auto& child : children) {
                            obj.push_back(convertVariantToJson(child));
                        }

                        return obj;
                    }
                case SpecialVariantValue::None:
                    return nlohmann::json::value_t::null;
                default:
                    throw std::runtime_error("Unsupported special variant value.");
            }
        case VariantType::Integer:
            return variant.getValueAs<int>();
        case VariantType::Float:
            return variant.getValueAs<float>();
        case VariantType::String:
            return variant.getValueAs<std::string>();
        case VariantType::Boolean:
            return variant.getValueAs<bool>();
        default:
            throw std::runtime_error("Unsupported variant type.");
    }
}

Variant JSONSerializer::convertJsonToVariant(const nlohmann::json& json) // NOLINT(*-no-recursion)
{
    auto v = Variant();

    if (json.is_object()) {
        for (auto it = json.begin(); it != json.end(); ++it) {
            v.addChild(it.key(), convertJsonToVariant(it.value()));
        }
    } else if (json.is_array()) {
        v = Variant::sequential();
        for (const auto& item : json) {
            v.addSequentialChild(convertJsonToVariant(item));
        }
    } else if (json.is_null()) {
        v.setValue(SpecialVariantValue::None);
    } else if (json.is_number_integer()) {
        v.setValue(json.get<int>());
    } else if (json.is_number_float()) {
        v.setValue(json.get<float>());
    } else if (json.is_string()) {
        v.setValue(json.get<std::string>());
    } else if (json.is_boolean()) {
        v.setValue(json.get<bool>());
    } else {
        throw std::runtime_error("Unsupported JSON type.");
    }

    return v;
}

JSONSerializer::JSONSerializer() = default;

void JSONSerializer::dump(std::ofstream& out, ISerializable* object) const
{
    if (out.is_open()) {
        auto v = Variant();
        object->serialize(v);
        const nlohmann::json result = convertVariantToJson(v);
        out << result.dump(4);

        out.close();
    } else {
        throw std::runtime_error("Unable to open stream for writing.");
    }
}

void JSONSerializer::load(std::ifstream& in, ISerializable* object) const
{
    if (in.is_open()) {
        nlohmann::json jsonData;
        in >> jsonData;

        auto v = convertJsonToVariant(jsonData);
        object->deserialize(v);

        in.close();
    } else {
        throw std::runtime_error("Unable to open stream for reading.");
    }
}
