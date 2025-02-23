#include <iostream>
#include "GeometryLib.h"

int main() {
    GeometryLib::Circle<double> c;
    std::cout << "Circle Area: " << c.area() << std::endl;
    return 0;
}
