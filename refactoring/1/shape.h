#pragma once
#include<string>
#include <vector>

class Coordinates {
public:
    std::vector<int> values{};

    explicit Coordinates(int one = 0, int two = 0, int three = 0, int four = 0, int five = 0, int six = 0, int seven = 0, int eight = 0)
            : values{{one, two, three, four, five, six, seven, eight}} {
    }
};

class Shape
{
public:
    enum Type {
        LINE = 0,
        SQUARE,
        CUBE,
        CIRCLE,
        CYLINDER,
        ENOTHER
    };

    Shape() = default;
    Shape(Type _type, Coordinates x,Coordinates y,Coordinates z);
    Shape(Type _type, int _x1, int _y1, double R, double H);
    [[nodiscard]] int getType() const { return type; }

    Type type = Type::ENOTHER;
    std::vector<int> target_x{};
    std::vector<int> target_y{};
    std::vector<int> target_z{};

    double volume{0};
    double square{0};
    double height{0};
    double radius{0};
};