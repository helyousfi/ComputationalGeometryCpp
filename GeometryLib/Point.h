// Point.h
#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {
    class GEOMETRY_API Point {
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