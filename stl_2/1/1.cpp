#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> vect = {1, 1, 2, 5, 6, 1, 2, 4};
	std::cout << "[IN]: ";
	for_each(vect.begin(), vect.end(), [](const int& n) { std::cout << n << ' '; 
	});
	sort(vect.begin(), vect.end());
	auto it = unique(vect.begin(), vect.end());
	vect.erase(it, vect.end());
	std::cout << "\n[OUT]: ";
	for_each(vect.begin(), vect.end(), [](const int& n) { std::cout << n << ' '; 
	});
}

//Задача 1. Уникальный вектор
//
//Описание
//
//Нужно реализовать функцию, которая удаляет все дубликаты, а не только подряд идущие, из std::vector.
//
//Пример правильной работы программы
//
//[IN]: 1 1 2 5 6 1 2 4
//[OUT]: 1 2 4 5 6