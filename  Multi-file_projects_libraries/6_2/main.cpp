#include <iostream>
#include <string>
#include "classCounter.h"


int main(int argc, char *argv[]) {
	std::string answ;
	Counter c;
	while(1){
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> answ;
		if(answ == "да"|| answ == "Да"||answ ==  "Da"|| answ == "yes"|| answ == "Yes"){
			std::cout << "Введите начальное значение счётчика: ";
			int firstCount = 0;
			std::cin >> firstCount;
			c = Counter(firstCount);
			break;
		}else if(answ == "no"|| answ == "No"||answ ==  "нет"|| answ == "Нет"|| answ == "неа"){
			break;
		}else{
			std::cout << "Введите да или нет!!!"<< std::endl;
		}
	}
	char comand;
	while (1) {
		std::cout << "Введите команду ('+', '-', '=' или 'x'(английская)): ";
		std::cin >> comand;
		if (comand == '+') {
			c.plusCount();
		}else if (comand == '-') {
			c.minusCount();
		}
		else if (comand == '=') {
			std::cout<< c.nowCount()<< std::endl;
		}
		else if (comand == 'x') {
			std::cout<< "Всего ХОРОШЕГО";
			break;
		}
		else{
			std::cout<<"Вы ввели неправильную команду, повторите ввод "<< std::endl;
		}
	}
	return 0;
}

