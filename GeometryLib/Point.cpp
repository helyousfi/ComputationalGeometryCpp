// Point.cpp
#include "pch.h"0
#include "Point.h"
#include <cmath>
#include <iostream>

namespace GeometryLib {
    template <typename T>
    Point<T>::Point() : x(0), y(0), name('?') {}

    template <typename T>
    Point<T>::Point(T x_, T y_) : x(x_), y(y_), name('?') {}

    template <typename T>
    Point<T>::Point(T x_, T y_, char name_) : x(x_), y(y_), name(name_) {}

    template <typename T>
    T Point<T>::GetX() { return x; }

    template <typename T>
    T Point<T>::GetY() { return y; }

    template <typename T>
    char Point<T>::GetName() { return name; }

    template <typename T>
    T Point<T>::distanceTo(const Point<T>& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    template <typename T>
    Point<T> Point<T>::operator+(const Point<T>& other) const { return { x + other.x, y + other.y }; }

    template <typename T>
    Point<T> Point<T>::operator-(const Point<T>& other) const { return { x - other.x, y - other.y }; }

    template <typename T>
    Point<T> Point<T>::operator*(T scalar) const { return { x * scalar, y * scalar }; }

    template <typename T>
    Point<T> Point<T>::operator/(T scalar) const { return { x / scalar, y / scalar }; }

    template <typename T>
    bool Point<T>::operator==(const Point<T>& other) const { return x == other.x && y == other.y; }

    template <typename T>
    bool Point<T>::operator!=(const Point<T>& other) const { return !(*this == other); }

    template <typename T>
    void Point<T>::print() const {
        std::cout << "(" << x << ", " << y << ") [" << name << "]\n";
    }

    // Explicit instantiation of the template for common types
    template class Point<int>;
    template class Point<float>;
    template class Point<double>;
}
