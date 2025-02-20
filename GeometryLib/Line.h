// Line.h
#ifndef LINE_H
#define LINE_H

#include "Point.h"

namespace GeometryLib {

    /**
     * @class Line
     * @brief Represents a line segment between two points.
     */
    class Line {
    public:
        Point start, end;

        Line();
        Line(const Point& start_, const Point& end_);

        double length() const;
        bool contains(const Point& p) const;

        void print() const;
    };

} // namespace GeometryLib

#endif // LINE_H