#include "print_info_func.h"
#include <iostream>
void print_info( Figure* fig) {
	if (fig->get_sides_count() == 3) {
		std::cout << fig->get_name() << ": \n"
		<< "Стороны: a = " << (fig)->getA()
		<< " b = " << (fig)->getB()
		<< " c = " << (fig)->getC() << "\n";
		std::cout << "Углы: A = " <<(fig)->getCapitalA()
		<< " B = " << (fig)->getCapitalB()
		<< " C = " << (fig)->getCapitalC() << "\n\n";
	} else if (fig->get_sides_count() == 4) {
		std::cout << fig->get_name() << ": \n"
		<< "Стороны: a = " << (fig)->getA()
		<< " b = " << (fig)->getB()
		<< " c = " << (fig)->getC()
		<< " d = " << (fig)->getD() << "\n";
		std::cout << "Углы: A = " << (fig)->getCapitalA()
		<< " B = " << (fig)->getCapitalB()
		<< " C = " << (fig)->getCapitalC()
		<< " D = " << (fig)->getCapitalD() << "\n\n";
	} else {
		std::cout << "Неправильное количество углов\n";
	}
}

