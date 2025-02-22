#ifndef UTILS_H
#define UTILS_H

#include "Point.h"


#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {

	/**
	 * @brief Determines if three points make a counterclockwise turn.
	 * @param a First point.
	 * @param b Second point.
	 * @param c Third point.
	 * @return Positive if counterclockwise, negative if clockwise, zero if collinear.
	 */
	GEOMETRY_API double ccw(const Point& a, const Point& b, const Point& c);

} 

#endif 
