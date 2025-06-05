#pragma once

#include <fstream>

#include "ISerializable.h"

class ISerializer
{
public:
    virtual ~ISerializer() = default;

    virtual void dump(std::ofstream& out, ISerializable* object) const = 0;

    virtual void load(std::ifstream& in, ISerializable* object) const = 0;
};
