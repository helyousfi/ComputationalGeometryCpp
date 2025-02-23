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

} 
