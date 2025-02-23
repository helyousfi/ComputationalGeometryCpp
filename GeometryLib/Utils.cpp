#include "pch.h"
#include "Utils.h"

namespace GeometryLib {

    // Assuming Point is a templated class
    template <typename T>
    double ccw(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

} // namespace GeometryLib

