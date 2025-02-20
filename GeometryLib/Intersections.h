#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "Line.h"
#include "Utils.h"  
#include <optional>  

namespace GeometryLib {
    bool intersection(const Line& line1, const Line& line2);
}

#endif
