#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"

namespace GeometryLib {

    class Polygon {
    private:
        std::vector<Point> vertices;

    public:
        // Constructors
        Polygon() = default;
        Polygon(const std::vector<Point>& points);

        // Accessors
        size_t size() const;
        const std::vector<Point>& getVertices() const;

        // Modifiers
        void addVertex(const Point& p);
        void removeVertex(size_t index);
        void clear();

        // Geometric Properties
        double area() const;
        bool isConvex() const;
        bool containsPoint(const Point& p) const;
        //bool isSimple() const;

        // Transformations
        void translate(double dx, double dy);
        void rotate(double angle, const Point& center);
        void scale(double factor, const Point& center);

        // Intersections
        bool intersects(const Polygon& other) const;

        // Utility Functions
        Polygon convexHull() const;
        void print() const;
    };

} // namespace GeometryLib

#endif // POLYGON_H
