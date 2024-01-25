#include "EquilateralTriangle.h"


EquilateralTriangle::EquilateralTriangle():Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60,60) {
    if((a != c || a != b || c != b) || ( A != 60 || B != 60 || C !=60)){
        throw MyError("Ошибка создания равностороннего треугольника. Стороны и/или углы не равны\n\n");
    }
}
