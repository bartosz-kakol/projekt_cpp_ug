#include "Position.h"
#include <cmath>

Position::Position(const int x, const int y)
    : x(x), y(y) { }

Position::Position()
    : x(-1), y(-1) { }

int Position::getX() const {
    return this->x;
}

void Position::setX(const int x) {
    if (x >= 0)
        this->x = x;
    else
        this->x = 0;
}

int Position::getY() const {
    return this->y;
}

void Position::setY(const int y) {
    if (y >= 0)
        this->y = y;
    else
        this->y = 0;
}

std::string Position::toString() const {
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

double Position::distance(const Position& position) const {
    const double dx = static_cast<double>(this->getX()) - static_cast<double>(position.getX());
    const double dy = static_cast<double>(this->getY()) - static_cast<double>(position.getY());
    return std::sqrt(dx * dx + dy * dy);
}

void Position::move(const int dx, const int dy) {
    setX(getX() + dx);
    setY(getY() + dy);
}

void Position::serialize(Variant& v)
{
    v.addChild("x", Variant::fromValue(x));
    v.addChild("y", Variant::fromValue(y));
}

void Position::deserialize(Variant& source)
{
    x = source.getChild("x").getValueAs<int>();
    y = source.getChild("y").getValueAs<int>();
}
