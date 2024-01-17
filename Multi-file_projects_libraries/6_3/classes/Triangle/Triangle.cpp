
#include "Triangle.h"	

Triangle::Triangle():Figure(3,"Треугольник"){
	this->a = 10;
	this->b = 20;
	this->c = 30;
	this->A = 50;
	this->B = 60;
	this->C = 70;
}
double Triangle::getA()   { return a; }
double Triangle::getB()   { return b; }
double Triangle::getC()   { return c; }
double Triangle::getCapitalA()  { return A; }
double Triangle::getCapitalB()  { return B; }
double Triangle::getCapitalC()  { return C; }
Triangle::Triangle(std::string name, double a, double b, double c, double A, double B, double C): Figure(3, name ) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
}