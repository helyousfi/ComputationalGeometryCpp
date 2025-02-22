#include "pch.h"
#include "Circle.h"
#include <iostream>

namespace GeometryLib {

    const double PI = 3.141592653589793;
    const double EPSILON = 1e-9; // Floating point tolerance

    // Default constructor (circle at origin with radius 1)
    Circle::Circle() : center(Point(0, 0)), radius(1) {}

    // Parameterized constructor
    Circle::Circle(const Point& center_, double radius_) : center(center_), radius(radius_) {}

    // Compute the diameter
    double Circle::diameter() const {
        return 2 * radius;
    }

    // Compute the circumference
    double Circle::circumference() const {
        return 2 * PI * radius;
    }

    // Compute the area
    double Circle::area() const {
        return PI * radius * radius;
    }

    // Check if a point is inside or on the circle
    bool Circle::contains(const Point& p) const {
        return center.distanceTo(p) <= radius + EPSILON;
    }

    // Check if two circles intersect
    bool Circle::intersectsWith(const Circle& other) const {
        double d = center.distanceTo(other.center);
        return d <= (radius + other.radius) && d >= fabs(radius - other.radius);
    }

    // Check if two circles are tangent to each other
    bool Circle::isTangentTo(const Circle& other) const {
        double d = center.distanceTo(other.center);
        return fabs(d - (radius + other.radius)) < EPSILON || fabs(d - fabs(radius - other.radius)) < EPSILON;
    }

    // Print circle details
    void Circle::print() const {
        std::cout << "Circle(Center: (" << center.x << ", " << center.y << "), Radius: " << radius << ")\n";
    }

} // namespace GeometryLib
