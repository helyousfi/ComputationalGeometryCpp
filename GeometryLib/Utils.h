#ifndef UTILS_H
#define UTILS_H

#include "Point.h"

namespace GeometryLib {

	/**
	 * @brief Determines if three points make a counterclockwise turn.
	 * @param a First point.
	 * @param b Second point.
	 * @param c Third point.
	 * @return Positive if counterclockwise, negative if clockwise, zero if collinear.
	 */
	double ccw(const Point& a, const Point& b, const Point& c);

} 

#endif 
