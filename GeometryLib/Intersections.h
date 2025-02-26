#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "Line.h"
#include "Circle.h"
#include "Polygon.h"
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

    // Template function to find the intersection of two circles
    template <typename T>
    GEOMETRY_API bool intersection(const Circle<T>& circle1, const Circle<T>& circle2);

    // Template function to find the intersection of two polygons
    template <typename T>
    GEOMETRY_API bool intersection(const Polygon<T>& polygon1, const Polygon<T>& polygon2);
}

#endif
