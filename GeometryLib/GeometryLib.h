// GeometryLib.h
// Main header file to include all modules
#ifndef GEOMETRYLIB_H
#define GEOMETRYLIB_H

#include <cmath>
#include <iostream>

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif


#include "pch.h"
#include "Point.h"
#include "Line.h"
#include "Line.h"
#include "Polygon.h"
#include "Circle.h"
// #include "ConvexHull.h"
// #include "Triangulation.h"
// #include "Intersections.h"
// #include "Utils.h"

#endif // GEOMETRYLIB_H