#include "Square.h"
#include <iostream>
#include <cmath> // Для std::abs

Square::Square(int x1, int y1, int x2, int y2, std::string name)
        : Shape(std::move(name)),
          topLeftLine(x1, y1, x1, y2),
          bottomLeftLine(x1, y2, x2, y2),
          bottomRightLine(x2, y2, x2, y1),
          topRightLine(x2, y1, x1, y1) {
    int a = std::abs(x1 - x2);
    int b = std::abs(y1 - y2);
    this->square = a * b;
    this->volume = 0; // Объем не применяется к квадрату
}

void Square::shift(int m, int n) {
    topLeftLine.shift(m, n);
    bottomLeftLine.shift(m, n);
    bottomRightLine.shift(m, n);
    topRightLine.shift(m, n);
}

void Square::scaleX(int a) {
    topLeftLine.scaleX(a);
    bottomLeftLine.scaleX(a);
    bottomRightLine.scaleX(a);
    topRightLine.scaleX(a);
}

void Square::scaleY(int d) {
    topLeftLine.scaleY(d);
    bottomLeftLine.scaleY(d);
    bottomRightLine.scaleY(d);
    topRightLine.scaleY(d);
}

void Square::scale(int s) {
    topLeftLine.scale(s);
    bottomLeftLine.scale(s);
    bottomRightLine.scale(s);
    topRightLine.scale(s);
}

std::string Square::getType() const {
    return name;
}

int Square::getX1() const {
    return topLeftLine.x1;
}

int Square::getY1() const {
    return topLeftLine.y1;
}

int Square::getX2() const {
    return bottomRightLine.x2;
}

int Square::getY2() const {
    return bottomRightLine.y2;
}

void Square::display() const {
    std::cout << "Rectangle:\n";
    topLeftLine.display();
    bottomLeftLine.display();
    bottomRightLine.display();
    topRightLine.display();
}
