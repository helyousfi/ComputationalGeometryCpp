// Line.h 
#ifndef LINE_H
#define LINE_H

#include "Point.h"

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {

    /**
     * Represents a line segment between two points.
     */
    template <typename T>
    class GEOMETRY_API Line {
    public:
        Point<T> start, end;

        // Constructors
        Line();
        Line(const Point<T>& start_, const Point<T>& end_);  

        T length() const;
        bool contains(const Point<T>& p) const;  
        T slope() const;
        Point<T> midpoint() const;

        void print() const;
    };

}

#endif // LINE_H
