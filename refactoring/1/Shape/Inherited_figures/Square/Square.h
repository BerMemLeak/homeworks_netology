#pragma once

#include "../Line/Line.h"
#include "../../shape.h"
#include <string>

class Square : public Shape {
public:
    Square(int x1, int y1, int x2, int y2, std::string name = "Rectangle");

    void shift(int m, int n) override;
    void scaleX(int a) override;
    void scaleY(int d) override;
    void scale(int s) override;

    [[nodiscard]] std::string getType() const override;
    [[nodiscard]] int getX1() const;
    [[nodiscard]] int getY1() const;
    [[nodiscard]] int getX2() const;
    [[nodiscard]] int getY2() const;

    void display() const;

private:
    Line topLeftLine;
    Line bottomLeftLine;
    Line bottomRightLine;
    Line topRightLine;
};
