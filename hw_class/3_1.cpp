#include <iostream>

class Calculator{
private:
	double num1;
	double num2;
public:
	Calculator(int num1 = 0, int num2 = 0){
		this->num1 = num1;
		this->num2 = num2;
	}
	double add(){
		return this->num1+this->num2;
	};
	double multiply(){
		return this->num1*this->num2;
	};
	double subtract_1_2(){
		return this->num1-this->num2;
	};
	double subtract_2_1(){
		return this->num2-this->num1;
	};
	double divide_1_2(){
		return this->num1/this->num2;
	};
	double divide_2_1(){
		return this->num2/this->num1;
	};
	
	bool set_num1(double num1){
		if(num1 == 0){
			return false;
		}else{
			this->num1 = num1;
			return true;
		}
	};
	bool set_num2(double num2){
		if(num2 == 0){
			return false;
		}else{
			this->num2 = num2;
			return true;
		}
	};
};


int main(int argc, char *argv[]) {
	//по заданию было предложено сделать завершение программы только после закрытия терминала
	while(1){
		double num1 = 0;
		double num2 = 0;
		std::cout << "Введите num1: ";
		std::cin >> num1;
		std::cout << "Введите num2: ";
		std::cin >> num2;
		Calculator calc(num1,num2);
		while(1){
			if(calc.set_num1(num1) && calc.set_num2(num2)){
				break;
			}else{
				std::cout << "Неверный Ввод"<< std::endl;
				std::cout << "Введите num1: ";
				std::cin >> num1;
				std::cout << "Введите num2: ";
				std::cin >> num2;
			}
		}
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
		std::cout << "\n";
		
	}
	
	return 0;
}