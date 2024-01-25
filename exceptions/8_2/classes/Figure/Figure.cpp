#include <iostream>
#include "Figure.h"


	Figure::Figure(){
		this->sides_count = 0;
		this->name = "Фигура";
	}
	Figure::~Figure() {}
	int Figure::get_sides_count() {
		return this->sides_count;
	}
	std::string Figure::get_name() {
		return this->name;
	}
	double Figure::getA()  { return 0; }
	double Figure::getB()  { return 0; }
	double Figure::getC()  { return 0; }
	double Figure::getD()  { return 0; }
	double Figure::getCapitalA()  { return 0; }
	double Figure::getCapitalB()  { return 0; }
	double Figure::getCapitalC()  { return 0; }
	double Figure::getCapitalD()  { return 0; }
	
	Figure::Figure(int count, const std::string& name){
		this->sides_count = count;
		this->name = name;
	}

