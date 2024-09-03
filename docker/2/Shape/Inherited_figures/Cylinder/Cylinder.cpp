#include "Cylinder.h"
#include <iostream>
#include <cmath>

Cylinder::Cylinder(double centerX, double centerY, double radius, double height, std::string name)
        : Circle(centerX, centerY, radius, std::move(name)), height(height) {
    volume = calculateVolume();
}

void Cylinder::shift(int dx, int dy) {
    Circle::shift(dx, dy);
}

void Cylinder::scaleX(int factor) {
    Circle::scaleX(factor);
    volume = calculateVolume();
}

void Cylinder::scaleY(int factor) {
    Circle::scaleY(factor);
    volume = calculateVolume();
}

void Cylinder::scale(int factor) {
    Circle::scale(factor);
    height *= factor;
    volume = calculateVolume();
}

double Cylinder::getHeight() const {
    return height;
}

double Cylinder::getVolume() const {
    return volume;
}

void Cylinder::display() const {
    Circle::display();
    std::cout << "Height: " << height << "\n";
    std::cout << "Volume: " << volume << "\n";
}

double Cylinder::calculateVolume() const {
    return Circle::getArea() * height;
}
