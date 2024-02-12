#pragma once
#include <iostream>
class Greeter{
public:
	Greeter(std::string name);
	std::string getName();
private:
	std::string name;
	
};