#pragma once

#include <any>

enum class SpecialVariantValue
{
    Object,
    Sequential,
    None
};

enum class VariantType
{
    Special,
    Integer,
    Float,
    String,
    Boolean
};

class Variant {
    std::any value;
    VariantType type;
    std::unordered_map<std::string, Variant> children;
    std::vector<Variant> sequentialChildren;

    static VariantType determineVariantType(const std::type_info& type);

    void ensureIsSequential() const;
public:
    Variant();
    Variant(std::any value, VariantType type);

    template<typename T>
    static Variant fromValue(T value);
    static Variant sequential();
    static Variant none();

    template<typename T>
    static Variant sequential(std::vector<T> values);

    template<typename T>
    static Variant sequential(std::vector<T> values, std::function<Variant(T&)> converter);

    std::any getValue() const;
    template<typename T>
    void setValue(T value);

    VariantType getType() const;

    template<typename T>
    T getValueAs() const;

    void addChild(const std::string& key, const Variant& child);
    void addChild(const std::string& key);
    Variant& getChild(const std::string& key);

    void addSequentialChild();
    void addSequentialChild(const Variant& child);

    std::unordered_map<std::string, Variant>& getChildren();
    std::vector<Variant> getSequentialChildren();

    template<typename T>
    std::vector<T> getSequentialChildren(std::function<T(Variant&)> converter) const;
};

#include "Variant.tpp"
