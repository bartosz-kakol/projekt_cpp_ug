#pragma once

#include <string>

class Position {
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

    double distance(Position position) const;

    void move(int dx, int dy);
};