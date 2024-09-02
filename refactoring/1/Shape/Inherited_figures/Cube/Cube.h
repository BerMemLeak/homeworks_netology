#pragma once
#include "../Square/Square.h"
#include <string>
#include <stdexcept>

class Cube : public Square {
public:
    Cube(int x1, int y1, int x2, int y2, int z1, int z2, std::string name = "Cube");

    void shift(int m, int n, int o);
    void scale(int s) override;
    [[nodiscard]] int getVolume() const;
    [[nodiscard]] std::string getType() const override;
    void scaleX(int factor) override;
    void scaleY(int factor) override;
    void scaleZ(int factor);

    void display() const;

private:
    int z1, z2;
    int volume;

    int calculateVolume() const;
};
