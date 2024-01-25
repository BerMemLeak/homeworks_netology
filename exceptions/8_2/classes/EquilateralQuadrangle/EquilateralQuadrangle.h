#pragma once
#include "../Quadrangle/Quadrangle.h"
#include "../../Errors/MyError.h"
class EquilateralQuadrangle: public Quadrangle{
public:
	EquilateralQuadrangle();
protected:
	EquilateralQuadrangle(std::string name, double a ,double A);
};