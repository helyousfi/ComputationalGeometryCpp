#include "pch.h"
#include "GeometryLib.h"
#include "Line.h"

namespace GeometryLib {

    Line::Line() : start(Point()), end(Point()) {}

    Line::Line(const Point& start_, const Point& end_) : start(start_), end(end_) {}

    double Line::length() const {
        return start.distanceTo(end);
    }

    bool Line::contains(const Point& p) const {
        double d1 = start.distanceTo(p);
        double d2 = p.distanceTo(end);
        double lineLength = length();
        return std::abs(d1 + d2 - lineLength) < 1e-9;
    }

    void Line::print() const {
        std::cout << "Line from ";
        start.print();
        std::cout << " to ";
        end.print();
        std::cout << std::endl;
    }

} // namespace GeometryLib

