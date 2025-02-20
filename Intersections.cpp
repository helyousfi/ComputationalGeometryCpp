#include "pch.h"
#include "Intersections.h"

namespace GeometryLib {

    bool intersection(const Line& line1, const Line& line2) {
        double o1 = ccw(line1.start, line1.end, line2.start);
        double o2 = ccw(line1.start, line1.end, line2.end);
        double o3 = ccw(line2.start, line2.end, line1.start);
        double o4 = ccw(line2.start, line2.end, line1.end);

        return (o1 * o2 <= 0) && (o3 * o4 <= 0);
    }

} // namespace GeometryLib

