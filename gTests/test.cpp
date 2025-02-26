#include "pch.h"
#include "Circle.h"
#include "Point.h"
#include <gtest/gtest.h>

using namespace GeometryLib;

// Define test cases
TEST(CircleTest, Properties) {
    Point<double> center(0.0, 0.0);
    Circle<double> circle(center, 5.0);

    EXPECT_DOUBLE_EQ(circle.diameter(), 10.0);
    EXPECT_NEAR(circle.circumference(), 31.4159, 1e-4);
    EXPECT_NEAR(circle.area(), 78.5398, 1e-4);
}

TEST(CircleTest, ContainsPoint) {
    Point<double> center(0.0, 0.0);
    Circle<double> circle(center, 5.0);

    Point<double> insidePoint(3.0, 4.0); // Distance = 5, on the edge
    Point<double> outsidePoint(6.0, 0.0); // Outside the circle

    EXPECT_TRUE(circle.contains(insidePoint));
    EXPECT_FALSE(circle.contains(outsidePoint));
}

TEST(CircleTest, Tangency) {
    Circle<double> c1(Point<double>(0.0, 0.0), 5.0);
    Circle<double> c2(Point<double>(10.0, 0.0), 5.0); // Externally tangent
    Circle<double> c3(Point<double>(5.0, 0.0), 5.0); // Intersecting

    EXPECT_TRUE(c1.isTangentTo(c2));
    EXPECT_FALSE(c1.isTangentTo(c3));
}
