#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle():Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60,50) {
    if((a != c) || ( A != C)){
        throw MyError("Ошибка создания равнобедренного треугольника. Стороны и/или углы на бедрах не равны\n\n");
    }
}
