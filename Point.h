// Point.h
#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

namespace GeometryLib {
    class Point {
    public:
        double x, y;
        char name;

        Point();
        Point(double x_, double y_);
        Point(double x_, double y_, char name_);

        double distanceTo(const Point& other) const;

        // Operator Overloading
        Point operator+(const Point& other) const;
        Point operator-(const Point& other) const;
        Point operator*(double scalar) const;
        Point operator/(double scalar) const;
        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;

        void print() const;
    };

}

#endif // POINT_H