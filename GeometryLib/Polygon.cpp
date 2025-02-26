#include "pch.h"
#include "Polygon.h"
#include <cmath>
#include <algorithm>
#include "Utils.h"

namespace GeometryLib {

    // Constructor
    template <typename T>
    Polygon<T>::Polygon(const std::vector<Point<T>>& points) : vertices(points) {}

    // Accessors
    template <typename T>
    size_t Polygon<T>::size() const {
        return vertices.size();
    }

    template <typename T>
    const std::vector<Point<T>>& Polygon<T>::getVertices() const {
        return vertices;
    }

    // Modifiers
    template <typename T>
    void Polygon<T>::addVertex(const Point<T>& p) {
        vertices.push_back(p);
    }

    template <typename T>
    void Polygon<T>::removeVertex(size_t index) {
        if (index < vertices.size()) {
            vertices.erase(vertices.begin() + index);
        }
    }

    template <typename T>
    void Polygon<T>::clear() {
        vertices.clear();
    }

    // Area using Shoelace Theorem
    template <typename T>
    double Polygon<T>::area() const {
        double sum = 0.0;
        size_t n = vertices.size();
        for (size_t i = 0; i < n; i++) {
            const Point<T>& p1 = vertices[i];
            const Point<T>& p2 = vertices[(i + 1) % n]; // Next point, wrapping around
            sum += (p1.x * p2.y - p2.x * p1.y);
        }
        return std::abs(sum) * 0.5;
    }

    // Check if convex (all ccw or cw)
    template <typename T>
    bool Polygon<T>::isConvex() const {
        if (vertices.size() < 3) return false;

        bool hasPositive = false, hasNegative = false;
        size_t n = vertices.size();

        for (size_t i = 0; i < n; i++) {
            double cross = ccw(vertices[i], vertices[(i + 1) % n], vertices[(i + 2) % n]);
            if (cross > 0) hasPositive = true;
            if (cross < 0) hasNegative = true;
            if (hasPositive && hasNegative) return false; // Mixed signs mean non-convex
        }
        return true;
    }

    // Check if point is inside polygon using Ray-Casting Algorithm
    template <typename T>
    bool Polygon<T>::containsPoint(const Point<T>& p) const {
        bool inside = false;
        size_t n = vertices.size();
        for (size_t i = 0, j = n - 1; i < n; j = i++) {
            const Point<T>& pi = vertices[i];
            const Point<T>& pj = vertices[j];
            if ((pi.y > p.y) != (pj.y > p.y) &&
                p.x < (pj.x - pi.x) * (p.y - pi.y) / (pj.y - pi.y) + pi.x) {
                inside = !inside;
            }
        }
        return inside;
    }

    // Translation
    template <typename T>
    void Polygon<T>::translate(double dx, double dy) {
        for (Point<T>& p : vertices) {
            p.x += dx;
            p.y += dy;
        }
    }

    // Rotation (around a given center)
    template <typename T>
    void Polygon<T>::rotate(double angle, const Point<T>& center) {
        double rad = angle * 3.14 / 180.0;
        double cosA = cos(rad), sinA = sin(rad);
        for (Point<T>& p : vertices) {
            double dx = p.x - center.x, dy = p.y - center.y;
            p.x = center.x + dx * cosA - dy * sinA;
            p.y = center.y + dx * sinA + dy * cosA;
        }
    }

    // Scaling (relative to a center)
    template <typename T>
    void Polygon<T>::scale(double factor, const Point<T>& center) {
        for (Point<T>& p : vertices) {
            p.x = center.x + factor * (p.x - center.x);
            p.y = center.y + factor * (p.y - center.y);
        }
    }

    // Convex Hull (Graham Scan)
    template <typename T>
    Polygon<T> Polygon<T>::convexHull() const {
        std::vector<Point<T>> hull = vertices;
        std::sort(hull.begin(), hull.end(), [](const Point<T>& a, const Point<T>& b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
            });

        std::vector<Point<T>> up, down;
        for (const auto& p : hull) {
            while (up.size() > 1 && ccw(up[up.size() - 2], up.back(), p) <= 0) up.pop_back();
            while (down.size() > 1 && ccw(down[down.size() - 2], down.back(), p) >= 0) down.pop_back();
            up.push_back(p);
            down.push_back(p);
        }

        up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
        return Polygon<T>(up);
    }

    template <typename T>
    void Polygon<T>::print() const {
        std::cout << "Polygon with " << vertices.size() << " vertices:\n";
        for (const auto& vertex : vertices) {
            std::cout << "(" << vertex.x << ", " << vertex.y << ")\n";
        }
    }

} // namespace GeometryLib
