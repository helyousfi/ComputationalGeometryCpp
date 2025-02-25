// Point.h
#ifndef POINT_H
#define POINT_H

#include <iostream>

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {
    template <typename T>
    class Point {
    private:
        T x, y;
        char name;

    public:
        // Constructors
        Point();
        Point(T x_, T y_);
        Point(T x_, T y_, char name_);

        // Getters
        T GetX() const;
        T GetY() const;
        char GetName() const;

        T distanceTo(const Point<T>& other) const;

        Point<T> operator+(const Point<T>& other) const;
        Point<T> operator-(const Point<T>& other) const;
        Point<T> operator*(T scalar) const;
        Point<T> operator/(T scalar) const;
        bool operator==(const Point<T>& other) const;
        bool operator!=(const Point<T>& other) const;

        // Print a point
        void print() const;
    };
}

#endif // POINT_H
