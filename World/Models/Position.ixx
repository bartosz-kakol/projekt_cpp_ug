module;

#include <string>

export module World.Models.Position;

export class Position {
    int x;
    int y;

public:
    Position(const int x, const int y)
        : x(x), y(y)
    {

    }

    Position()
        : x(-1), y(-1)
    {

    }

    [[nodiscard]] int getX() const
    {
        return this->x;
    }

    void setX(int x)
    {
        if (x >= 0)
            this->x = x;
        else
            this->x = 0;
    }

    [[nodiscard]] int getY() const
    {
        return this->y;
    }

    void setY(int y)
    {
        if (y >= 0)
            this->y = y;
        else
            this->y = 0;
    }

    [[nodiscard]] std::string toString() const
    {
        return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
    }

    [[nodiscard]] double distance(Position position) const
    {
        const double dx = static_cast<double>(this->getX()) - static_cast<double>(position.getX());
        const double dy = static_cast<double>(this->getY()) - static_cast<double>(position.getY());

        return sqrt(dx * dx + dy * dy);
    }

    void move(const int dx, const int dy)
    {
        setX(getX() + dx);
        setY(getY() + dy);
    }
};
