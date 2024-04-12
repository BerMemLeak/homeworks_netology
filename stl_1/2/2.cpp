#include <iostream>
#include "map"
using namespace std;

struct Compare {
	bool operator()(const int& a, const int& b) const {
		return a > b; 
	}
};


int main(int argc, char *argv[]) {
	std::cout << "[IN]: \n";
	int count = 0;
	std::cin >> count;
	std::map <int, int,Compare> nums;
	for (int i = 0; i < count; i++) {
		int chislo;
		std::cin >> chislo;
		nums.insert( std::pair<int,int>(chislo,i) );
	}
	std::cout <<"[OUT]\n";
	for (const auto& elem : nums){
		std::cout <<elem.first <<std::endl;
	}
}


//Задача 2. Удаление дубликатов
//Описание
//Вам поступают числа из стандартного потока ввода. Первым числом вводится количество элементов, далее сами значения.
//
//Нужно вывести все эти числа без дубликатов в порядке убывания.
//
//Пример правильной работы программы
//[IN]:
//6
//1
//5
//1
//3
//4
//4
//[OUT]: 
//5
//4
//3
//1