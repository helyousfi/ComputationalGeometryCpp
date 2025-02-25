#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <cmath>

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {
    template <typename T>
    class GEOMETRY_API Circle {
    public:
        Point<T> center;
        T radius;

        Circle();
        Circle(const Point<T>& center_, T radius_);

        // Properties
        T diameter() const;
        T circumference() const;
        T area() const;

        // Geometric Operations
        bool contains(const Point<T>& p) const;
        bool isTangentTo(const Circle<T>& other) const;

        // Utility Methods
        void print() const;
    };
}

#endif // CIRCLE_H
