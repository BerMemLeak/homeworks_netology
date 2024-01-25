#include "RightTriangle.h"

RightTriangle::RightTriangle():Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 60,9) {
    if(C != 90.0){
        throw MyError("Ошибка создания прямоугольного треугольника. Угол С не равен  90\n\n");
    }
}
