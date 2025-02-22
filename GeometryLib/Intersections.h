#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "Line.h"
#include "Utils.h"  
#include <optional>  

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {
    // Line intersection
    GEOMETRY_API bool intersection(const Line& line1, const Line& line2);
}

#endif
