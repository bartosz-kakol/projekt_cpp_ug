#pragma once

#include <string>

#include "Serializer/Base/Interfaces/ISerializable.h"

class Position : public ISerializable {
    int x;
    int y;

public:
    Position(int x, int y);
    Position();

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    std::string toString() const;

    double distance(const Position& position) const;

    void move(int dx, int dy);

    void serialize(Variant& v) override;
    void deserialize(Variant& source) override;
};
