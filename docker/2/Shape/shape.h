#pragma once

#include <string>
#include <utility>

class Shape {
public:
    explicit Shape(std::string name) : name(std::move(name)) {}

    virtual std::string getType() const = 0;
    virtual ~Shape() = default;

    virtual void shift(int m, int n) = 0;
    virtual void scaleX(int a) = 0;
    virtual void scaleY(int d) = 0;
    virtual void scale(int e) = 0;

protected:
    std::string name;
    double volume{0};
    double square{0};
    double height{0};
    double radius{0};
};

