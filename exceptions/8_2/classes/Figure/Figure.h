#pragma once
#include "iostream"

class Figure{
public:
	Figure();
  virtual ~Figure();
	int get_sides_count();
	std::string get_name();
	virtual double getA();
	virtual double getB();
	virtual double getC();
	virtual double getD();
	virtual double getCapitalA();
	virtual double getCapitalB();
	virtual double getCapitalC();
	virtual double getCapitalD();
protected:
	Figure(int count, const std::string& name);
	int sides_count;
	std::string name;
};