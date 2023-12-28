#include <iostream>


class Figure{
public:
	Figure(){
		this->sides_count = 0;
		this->name = "Фигура";
	}

	int get_sides_count(){
		return this->sides_count;
	}
	std::string get_name(){
		return this->name;
	}
protected:
	Figure(int count, std::string name){
		this->sides_count = count;
		this->name = name;
	}
	int sides_count;
	std::string name;
};

class Triangle: public Figure{
public:
	Triangle():Figure(3,"Треугольник"){}
};
class Quadrangle: public Figure{
public:
	Quadrangle(): Figure(4, "Четырехугольник") {}
};

using namespace std;
int main(int argc, char *argv[]) {
	Figure fig;
	std::cout << "Количество сторон: \n";
	std::cout << fig.get_name() <<": " << fig.get_sides_count()<< "\n";
	Triangle tri;
	std::cout << tri.get_name() <<": " << tri.get_sides_count()<< "\n";
	Quadrangle quad;
	std::cout << quad.get_name() <<": " << quad.get_sides_count()<< "\n";
	return 0;

}



//Задача 1. Фигуры. Количество сторон
//
//В этом задании вы построите первую простую иерархию классов для заданной предметной области.
//
//Предметная область выглядит следующим образом: есть сущность фигура. Фигуры бывают двух типов: треугольник и четырёхугольник. У фигуры есть количество сторон. Для неизвестной фигуры будем считать это количество равным нулю. У треугольника три стороны, у четырёхугольника четыре стороны. У любой фигуры мы хотим узнавать количество её сторон, но мы не должны быть способны изменить количество сторон для заданной фигуры извне.
//
//Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу: создайте по одному экземпляру каждого класса и выведите информацию о количестве его сторон на консоль.
//
//Пример работы программы
//
//Консоль
//
//Количество сторон:
//Фигура: 0
//Треугольник: 3
//Четырёхугольник: 4
