#include <iostream>
#include "Quadrangle.h"


Quadrangle::Quadrangle():Figure(4,"Четырехугольник"){
	this->a = 10;
	this->b = 20;
	this->c = 30;
	this->d = 40;
	this->A = 90;
	this->B = 90;
	this->C = 70;
	this->D = 110;
    if(((A + B + C + D)!=360) || sides_count != 4)
    {
        throw MyError("Ошибка создания четырехугольника. Причина: сумма углов не равна 360 или количество сторон не 4\n\n");
    }
}
double Quadrangle::getA()  { return a; }
double Quadrangle::getB()  { return b; }
double Quadrangle::getC()  { return c; }
double Quadrangle::getD()  { return d; }
double Quadrangle::getCapitalA()  { return A; }
double Quadrangle::getCapitalB()  { return B; }
double Quadrangle::getCapitalC()  { return C; }
double Quadrangle::getCapitalD()  { return D; }

Quadrangle::Quadrangle(std::string name, double a, double b, double c,double d, double A, double B, double C,double D): Figure(4, name ) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
};
	
