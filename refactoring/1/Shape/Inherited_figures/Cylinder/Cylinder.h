#pragma once

#include "../Circle/Circle.h"
#include <string>

class Cylinder : public Circle {
public:
    Cylinder(double centerX, double centerY, double radius, double height, std::string name = "Cylinder");

    void shift(int dx, int dy) override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scale(int factor) override;

    [[nodiscard]] double getHeight() const;
    [[nodiscard]] double getVolume() const;

    void display() const override;

private:
    double height;
    double volume;

    double calculateVolume() const;
};
