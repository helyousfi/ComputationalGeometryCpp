#include "pch.h"
#include "GeometryLib.h"
#include "Line.h"

namespace GeometryLib {
    template <typename T>
    Line<T>::Line() : start(Point<T>()), end(Point<T>()) {}

    template <typename T>
    Line<T>::Line(const Point<T>& start_, const Point<T>& end_) : start(start_), end(end_) {}

    template <typename T>
    T Line<T>::length() const {
        return start.distanceTo(end);
    }

    template <typename T>
    bool Line<T>::contains(const Point<T>& p) const {
        double d1 = start.distanceTo(p);
        double d2 = p.distanceTo(end);
        double lineLength = length();
        return std::abs(d1 + d2 - lineLength) < 1e-9;
    }

    template <typename T>
    T Line<T>::slope() const {
        return (end.GetY() - start.GetY()) / (end.GetX() - start.GetX())
    }

    template <typename T>
    Point<T> Line<T>::midpoint() const {  
        Point<T> midPoint;
        midPoint = (start + end) / 2;
        return midPoint;
    }

    template <typename T>
    void Line<T>::print() const {
        std::cout << "Line from ";
        start.print();
        std::cout << " to ";
        end.print();
        std::cout << std::endl;
    }

} 
