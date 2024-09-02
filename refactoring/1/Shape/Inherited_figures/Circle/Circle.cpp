#include "Circle.h"
#include <iostream>

Circle::Circle(double centerX, double centerY, double radius, std::string name)
        : Shape(std::move(name)), centerX(centerX), centerY(centerY), radius(radius) {
    // Вычисляем площадь круга
    square = calculateArea();
}

std::string Circle::getType() const {
    return name;
}

void Circle::shift(int dx, int dy) {
    centerX += dx;
    centerY += dy;
}

void Circle::scaleX(int factor) {
    radius *= factor;
    updateArea();
}

void Circle::scaleY(int factor) {
    radius *= factor;
    updateArea();
}

void Circle::scale(int factor) {
    radius *= factor;
    updateArea();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getCenterX() const {
    return centerX;
}

double Circle::getCenterY() const {
    return centerY;
}

double Circle::getArea() const {
    return square;
}

void Circle::display() const {
    std::cout << "Circle:\n";
    std::cout << "Center: (" << centerX << ", " << centerY << ")\n";
    std::cout << "Radius: " << radius << "\n";
    std::cout << "Area: " << square << "\n";
}

void Circle::updateArea() {
    square = calculateArea();
}

double Circle::calculateArea() const {
    return M_PI * radius * radius;
}
