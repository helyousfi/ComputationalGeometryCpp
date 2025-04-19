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
        char name;

        // Constructors
        Line();
        Line(const Point<T>& start_, const Point<T>& end_);  
        Line(const Point<T>& start_, const Point<T>& end_, char name_);

        char GetName() const;
        T distanceTo(const Point<T>& point) const;

        T length() const;
        bool contains(const Point<T>& p) const;  
        T slope() const;
        Point<T> midpoint() const;

        void print() const;
    };

    // Explicit instantiation of the template for common types
    template class GEOMETRY_API Line<int>;
    template class GEOMETRY_API Line<double>;
    template class GEOMETRY_API Line<float>;
}

#endif // LINE_H
