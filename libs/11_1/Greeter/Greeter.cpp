#include <iostream>
#include "Greeter.h"

Greeter::Greeter(std::string name){
	this->name = name;
};

std::string Greeter::getName(){
	  return this->name;
};