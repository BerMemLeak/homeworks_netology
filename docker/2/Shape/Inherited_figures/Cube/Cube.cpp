#include "Cube.h"
#include <iostream>
#include <cmath>    // Для abs

Cube::Cube(int x1, int y1, int x2, int y2, int z1, int z2, std::string name)
        : Square(x1, y1, x2, y2, std::move(name)), z1(z1), z2(z2) {
    if (std::abs(x2 - x1) != std::abs(z2 - z1)) {
        throw std::invalid_argument("Такого куба не может существовать");
    }
    volume = calculateVolume();
}

void Cube::shift(int m, int n, int o) {
    Square::shift(m, n);
    z1 += o;
    z2 += o;
}

void Cube::scale(int s) {
    Square::scale(s);
    z2 = z1 + (z2 - z1) * s;
    volume = calculateVolume();
}

int Cube::getVolume() const {
    return volume;
}

std::string Cube::getType() const {
    return "Cube";
}

void Cube::scaleX(int factor) {
    Square::scaleX(factor);
    int sideLength = std::abs(Square::getX2() - Square::getX1());
    z2 = z1 + sideLength;
    volume = calculateVolume();
}

void Cube::scaleY(int factor) {
    Square::scaleY(factor);
    int sideLength = std::abs(Square::getY2() - Square::getY1());
    z2 = z1 + sideLength;
    volume = calculateVolume();
}

void Cube::scaleZ(int factor) {
    int height = std::abs(z2 - z1);
    z2 = z1 + height * factor;
    volume = calculateVolume();
}

void Cube::display() const {
    Square::display();
    std::cout << "Depth (Z): " << z1 << " to " << z2 << "\n";
    std::cout << "Volume: " << volume << "\n";
}

int Cube::calculateVolume() const {
    int sideLength = std::abs(Square::getX2() - Square::getX1());
    int height = std::abs(z2 - z1);
    return sideLength * sideLength * height;
}
