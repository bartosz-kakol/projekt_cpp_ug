#include "Variant.h"

#include <utility>

VariantType Variant::determineVariantType(const std::type_info& type)
{
    if (type == typeid(SpecialVariantValue)) return VariantType::Special;
    if (type == typeid(int)) return VariantType::Integer;
    if (type == typeid(float)) return VariantType::Float;
    if (type == typeid(std::string)) return VariantType::String;
    if (type == typeid(bool)) return VariantType::Boolean;

    throw std::runtime_error("Niewspierany typ.");
}

void Variant::ensureIsSequential() const
{
    if (type != VariantType::Special || value.type() != typeid(SpecialVariantValue) || std::any_cast<SpecialVariantValue>(value) != SpecialVariantValue::Sequential)
    {
        throw std::runtime_error("Ten Variant nie jest sekwencyjny.");
    }
}

Variant::Variant()
    : value(SpecialVariantValue::Object), type(VariantType::Special)
{

}

Variant::Variant(std::any value, const VariantType type)
    : value(std::move(value)), type(type)
{

}

Variant Variant::sequential()
{
    return {SpecialVariantValue::Sequential, VariantType::Special};
}

Variant Variant::none()
{
    return {SpecialVariantValue::None, VariantType::Special};
}

std::any Variant::getValue() const
{
    return value;
}

VariantType Variant::getType() const
{
    return type;
}

void Variant::addChild(const std::string& key, const Variant& child)
{
    children[key] = child;
}

void Variant::addChild(const std::string& key)
{
    children[key] = Variant();
}

Variant& Variant::getChild(const std::string& key)
{
    return children[key];
}

void Variant::addSequentialChild()
{
    ensureIsSequential();

    addSequentialChild(Variant());
}

void Variant::addSequentialChild(const Variant& child)
{
    ensureIsSequential();

    sequentialChildren.emplace_back(child);
}

std::unordered_map<std::string, Variant>& Variant::getChildren()
{
    return children;
}

std::vector<Variant> Variant::getSequentialChildren()
{
    return sequentialChildren;
}


