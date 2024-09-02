#pragma once
#include <string>
#include "../../shape.h" // Убедитесь, что путь к заголовочному файлу правильный
#include <cmath>    // Для математических функций

class Circle : public Shape {
public:
    explicit Circle(double centerX, double centerY, double radius, std::string name = "Circle");

    std::string getType() const override;
    void shift(int dx, int dy) override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scale(int factor) override;

    [[nodiscard]] double getRadius() const;
    [[nodiscard]] double getCenterX() const;
    [[nodiscard]] double getCenterY() const;
    [[nodiscard]] double getArea() const;

    virtual void display() const;

private:
    double centerX;
    double centerY;
    double radius;
    double square;

    void updateArea();
    double calculateArea() const;
};
