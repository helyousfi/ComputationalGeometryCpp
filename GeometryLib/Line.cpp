#include "pch.h"
#include "GeometryLib.h"
#include "Line.h"

namespace GeometryLib {
    template <typename T>
    Line<T>::Line() : start(Point<T>()), end(Point<T>()) { name = std::string(1, start.GetName()) + end.GetName(); }

    template <typename T>
    Line<T>::Line(const Point<T>& start_, const Point<T>& end_) : start(start_), end(end_) { name = std::string(1, start.GetName()) + end.GetName(); }

    template <typename T>
    Line<T>::Line(const Point<T>& start_, const Point<T>& end_, const std::string& name_)
        : start(start_), end(end_), name(name_) {}

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
        return (end.GetY() - start.GetY()) / (end.GetX() - start.GetX());
    }

    template <typename T>
    std::string Line<T>::GetName() const {
        return name;
    }

    template <typename T>
    T Line<T>::distanceTo(const Point<T>& point) const {
        T x0 = point.GetX();
        T y0 = point.GetY();
        T x1 = start.GetX();
        T y1 = start.GetY();
        T x2 = end.GetX();
        T y2 = end.GetY();

        T numerator = std::abs((x2 - x1) * (y1 - y0) - (x1 - x0) * (y2 - y1));
        T denominator = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        return numerator / denominator;
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
