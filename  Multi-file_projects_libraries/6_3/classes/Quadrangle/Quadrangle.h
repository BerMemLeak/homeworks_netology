#pragma once
#include "../Figure/Figure.h"

class Quadrangle: public Figure{
public:
	Quadrangle();
	double getA() override;
    double getB() override;
    double getC() override;
    double getD() override;
    double getCapitalA() override;
    double getCapitalB() override;
    double getCapitalC() override;
	double getCapitalD() override;
protected:
	double a;
	double b;
	double c;
	double d;
	double A;
	double B;
	double C;
	double D;
	Quadrangle(std::string name, double a, double b, double c,double d, double A, double B, double C,double D);
};