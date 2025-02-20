// Point.cpp
#include "pch.h"
#include "GeometryLib.h"

namespace GeometryLib {

    Point::Point() : x(0), y(0), name('O') {}

    Point::Point(double x_, double y_) : x(x_), y(y_), name('O') {}

    Point::Point(double x_, double y_, char name_) : x(x_), y(y_), name(name_) {}

    double Point::distanceTo(const Point& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    Point Point::operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point Point::operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point Point::operator*(double scalar) const {
        return Point(x * scalar, y * scalar);
    }

    Point Point::operator/(double scalar) const {
        return Point(x / scalar, y / scalar);
    }

    bool Point::operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool Point::operator!=(const Point& other) const {
        return !(*this == other);
    }

    void Point::print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

} // namespace GeometryLib
