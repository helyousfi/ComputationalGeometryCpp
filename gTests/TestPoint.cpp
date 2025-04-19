#include "pch.h"
#include "Circle.h"
#include "Point.h"
#include <gtest/gtest.h>

using namespace GeometryLib;

// Define test cases
TEST(PointTest, Properties) {
    Point<double> center(0.0, 0.0, 'O');
    EXPECT_TRUE(center.GetName() == 'O');
}