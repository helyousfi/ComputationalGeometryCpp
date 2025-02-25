#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"

#ifdef GEOMETRYLIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport)
#endif

namespace GeometryLib {

    template <typename T>
    class GEOMETRY_API Polygon {
    private:
        std::vector<Point<T>> vertices;

    public:
        // Constructors
        Polygon() = default;
        Polygon(const std::vector<Point<T>>& points);

        // Accessors
        size_t size() const;
        const std::vector<Point<T>>& getVertices() const;

        // Modifiers
        void addVertex(const Point<T>& p);
        void removeVertex(size_t index);
        void clear();

        // Geometric Properties
        double area() const;
        bool isConvex() const;
        bool containsPoint(const Point<T>& p) const;

        // Transformations
        void translate(double dx, double dy);
        void rotate(double angle, const Point<T>& center);
        void scale(double factor, const Point<T>& center);

        // Utility Functions
        Polygon<T> convexHull() const;
        void print() const;
    };

} // namespace GeometryLib

#endif // POLYGON_H
