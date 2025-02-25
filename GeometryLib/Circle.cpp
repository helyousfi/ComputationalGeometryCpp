#include "pch.h"
#include "Circle.h"
#include <iostream>
#include <cmath>

namespace GeometryLib {

    const double PI = 3.141592653589793;
    const double EPSILON = 1e-9; // Floating point tolerance

    // Default constructor (circle at origin with radius 1)
    template <typename T>
    Circle<T>::Circle() : center(Point<T>(0, 0)), radius(1) {}

    // Parameterized constructor
    template <typename T>
    Circle<T>::Circle(const Point<T>& center_, T radius_) : center(center_), radius(radius_) {}

    // Compute the diameter
    template <typename T>
    T Circle<T>::diameter() const {
        return 2 * radius;
    }

    // Compute the circumference
    template <typename T>
    T Circle<T>::circumference() const {
        return 2 * PI * radius;
    }

    // Compute the area
    template <typename T>
    T Circle<T>::area() const {
        return PI * radius * radius;
    }

    // Check if a point is inside or on the circle
    template <typename T>
    bool Circle<T>::contains(const Point<T>& p) const {
        return center.distanceTo(p) <= radius + EPSILON;
    }

    

    // Check if two circles are tangent to each other
    template <typename T>
    bool Circle<T>::isTangentTo(const Circle<T>& other) const {
        double d = center.distanceTo(other.center);
        return fabs(d - (radius + other.radius)) < EPSILON || fabs(d - fabs(radius - other.radius)) < EPSILON;
    }

    // Print circle details
    template <typename T>
    void Circle<T>::print() const {
        std::cout << "Circle(Center: ("; 
        center.print();
        std::cout << "), Radius: " << radius << ")\n";
    }

    // Explicit instantiation (optional, if needed for common types like double, float)
    template class Circle<double>;
    template class Circle<float>;

} // namespace GeometryLib
