#include "pch.h"
#include "Intersections.h"

namespace GeometryLib {

    template <typename T>
    bool intersection(const Line<T>& line1, const Line<T>& line2) {
        // Calculate CCW for all four pairs of points
        double o1 = ccw(line1.start, line1.end, line2.start);
        double o2 = ccw(line1.start, line1.end, line2.end);
        double o3 = ccw(line2.start, line2.end, line1.start);
        double o4 = ccw(line2.start, line2.end, line1.end);

        // General case: line segments intersect
        if ((o1 * o2 <= 0) && (o3 * o4 <= 0)) {
            return true;
        }

        return false;  
    }
    template <typename T>
    GEOMETRY_API bool intersection(const Circle<T>& circle1, const Circle<T>& circle2)
    {
        double d = circle1.center.distanceTo(circle2.center);
        return d <= (circle1.radius + circle2.radius) && d >= fabs(circle1.radius - circle2.radius);
    }

    template <typename T>
    GEOMETRY_API bool intersection(const Polygon<T>& polygon1, const Polygon<T>& polygon2)
    {
        for (const Point<T>& p : polygon2.getVertices()) {
            if (polygon1.containsPoint(p)) return true;
        }
        for (const Point<T>& p : polygon1.getVertices()) {
            if (polygon2.containsPoint(p)) return true;
        }
        return false;
    }

} 
