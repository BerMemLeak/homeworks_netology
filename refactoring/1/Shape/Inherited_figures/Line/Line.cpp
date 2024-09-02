#include "Line.h"
#include <iostream>

Line::Line(int x1, int y1, int x2, int y2, std::string name)
        : Shape(std::move(name)), x1(x1), y1(y1), x2(x2), y2(y2) {}

void Line::shift(int m, int n) {
    x1 += m;
    y1 += n;
    x2 += m;
    y2 += n;
}

void Line::scaleX(int a) {
    x1 *= a;
    x2 *= a;
}

void Line::scaleY(int d) {
    y1 *= d;
    y2 *= d;
}

void Line::scale(int s) {
    x1 /= s;
    y1 /= s;
    x2 /= s;
    y2 /= s;
}

std::string Line::getType() const {
    return name;
}

void Line::display() const {
    std::cout << "Line: от (" << x1 << ", " << y1 << ") до (" << x2 << ", " << y2 << ")\n";
}
