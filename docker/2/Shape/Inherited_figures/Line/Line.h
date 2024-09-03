#pragma once
#include "../../shape.h"
#include <string>

class Line : public Shape {
public:
    explicit Line(int x1, int y1, int x2, int y2, std::string name = "Line");

    void shift(int m, int n) override;
    void scaleX(int a) override;
    void scaleY(int d) override;
    void scale(int s) override;

    [[nodiscard]] std::string getType() const override;
    void display() const;

//protected:
    int x1, y1, x2, y2;
};
