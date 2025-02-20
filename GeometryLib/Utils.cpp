#include "pch.h"
#include "Utils.h"

namespace GeometryLib {

    double ccw(const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

} // namespace GeometryLib
