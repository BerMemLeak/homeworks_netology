#include "EquilateralQuadrangle.h"


EquilateralQuadrangle::EquilateralQuadrangle():Quadrangle("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {
    if(((a != c)&&(b != d)) || ( A != 90 || B != 90 || C !=90)){
        throw MyError("Ошибка создания прямоугольника. \n\n");
    }
};
EquilateralQuadrangle::EquilateralQuadrangle(std::string name, double a ,double A):Quadrangle(name, a,a,a,a,A,A,A,A) {};
	

