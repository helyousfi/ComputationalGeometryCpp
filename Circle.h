#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <cmath>

namespace GeometryLib {
    class Circle {
    public:
        Point center;
        double radius;
        Circle();
        Circle(const Point& center_, double radius_);

        // Properties
        double diameter() const;
        double circumference() const;
        double area() const;

        // Geometric Operations
        bool contains(const Point& p) const;
        bool intersectsWith(const Circle& other) const;
        bool isTangentTo(const Circle& other) const;

        // Utility Methods
        void print() const;
    };

} 
#endif 
