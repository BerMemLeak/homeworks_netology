#include <iostream>

void print(std::vector<int> &mass);
int main(int argc, char *argv[]) {
	std::vector<int> mass = {4, 7, 9, 14, 12 };
	std::cout <<"Входные данные:  ";
	print(mass);
	std::cout <<"\nВыходные данные:  ";
	std::for_each(mass.begin(),mass.end(), [](int &a)mutable{
		if (a % 2 != 0) {
			a *=3;
		}
	}); 
	print(mass);
}
void print(std::vector<int> &mass){
	for (int i : mass) {
		std::cout << i <<"\t";
	}
};

//Задача 1. Лямбда-функция
//
//Описание
//
//Напишите программу, которая все нечётные элементы массива (std::vector) умножает на 3 с помощью лямбда-функции.
//
//Циклы использовать не нужно.