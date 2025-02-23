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
    // Template function to find the intersection of two lines
    template <typename T>
    GEOMETRY_API bool intersection(const Line<T>& line1, const Line<T>& line2);
}

#endif
