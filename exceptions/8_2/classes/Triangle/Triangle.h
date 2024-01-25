#pragma once 
#include <iostream>
#include "../Figure/Figure.h"

class Triangle: public Figure{
public:
	Triangle();
	double getA() override;
	double getB() override;
	double getC() override;
	double getCapitalA() override;
	double getCapitalB() override;
	double getCapitalC() override;
protected:
	double a;
	double b;
	double c;
	double A;
	double B;
	double C;
	Triangle(const std::string& name, double a, double b, double c, double A, double B, double C) ;
};