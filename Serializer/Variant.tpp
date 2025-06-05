#pragma once

template<typename T>
Variant Variant::fromValue(T value)
{
    return Variant(value, determineVariantType(typeid(T)));
}

template<typename T>
Variant Variant::sequential(std::vector<T> values)
{
    Variant v = sequential();

    for (const auto& value : values) {
        v.addSequentialChild(Variant::fromValue(value));
    }

    return v;
}

template<typename T>
Variant Variant::sequential(std::vector<T> values, std::function<Variant(T&)> converter)
{
    Variant v = sequential();

    for (auto& value : values) {
        v.addSequentialChild(converter(value));
    }

    return v;
}

template<typename T>
void Variant::setValue(T value)
{
    this->value = value;
    this->type = determineVariantType(typeid(T));
}

template<typename T>
T Variant::getValueAs() const
{
    return std::any_cast<T>(value);
}

template <typename T>
std::vector<T> Variant::getSequentialChildren(std::function<T(Variant&)> converter) const
{
    std::vector<T> result;

    for (auto value: sequentialChildren) {
        result.push_back(converter(value));
    }

    return result;
}
