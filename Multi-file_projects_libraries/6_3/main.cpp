#include <iostream>
#include "classes/Figure/Figure.h"
#include "classes/Triangle/Triangle.h"
#include "classes/Quadrangle/Quadrangle.h"
#include "classes/RightTriangle/RightTriangle.h"
#include "classes/IsoscelesTriangle/IsoscelesTriangle.h"
#include "classes/EquilateralTriangle/EquilateralTriangle.h"
#include "classes/EquilateralQuadrangle/EquilateralQuadrangle.h"
#include "classes/Square/Square.h"
#include "classes/Parallelogram/Parallelogram.h"
#include "classes/Rhombus/Rhombus.h"
#include "print_info_func/print_info_func.h"

#include "classes/Figure/Figure.cpp"
#include "classes/Triangle/Triangle.cpp"
#include "classes/Quadrangle/Quadrangle.cpp"
#include "classes/RightTriangle/RightTriangle.cpp"
#include "classes/IsoscelesTriangle/IsoscelesTriangle.cpp"
#include "classes/EquilateralTriangle/EquilateralTriangle.cpp"
#include "classes/EquilateralQuadrangle/EquilateralQuadrangle.cpp"
#include "classes/Square/Square.cpp"
#include "classes/Parallelogram/Parallelogram.cpp"
#include "classes/Rhombus/Rhombus.cpp"
#include "print_info_func/print_info_func.cpp"

int main(int argc, char *argv[]) {
	Triangle tri;
	print_info(&tri);
	RightTriangle q;
	print_info(&q);
	IsoscelesTriangle w;
	print_info(&w);
	EquilateralTriangle e;
	print_info(&e);
	EquilateralQuadrangle r;
	print_info(&r);
	Square t;
	print_info(&t);
	Parallelogram a;
	print_info(&a);
	Rhombus d;
	print_info(&d);
	return 0;
}


//
//
//Задача 2. Фигуры. Стороны и углы
//
//В этом задании вы усложните иерархию классов для усложнённой предметной области.
//
//У вас появляется информация о длине сторон и углах ваших фигур, а также несколько более конкретных фигур. Теперь в треугольнике вы должны хранить информацию о длине всех его трёх сторон (a, b, c) и значениях его трёх углов (A, B, C). В четырёхугольнике вы храните информацию о длине его четырёх сторон (a, b, c, d) и значениях его четырёх углов (A, B, C, D).
//
//Также у вас появляются более конкретные фигуры:
//
//прямоугольный треугольник (угол C всегда равен 90);
//равнобедренный треугольник (стороны a и c равны, углы A и C равны);
//равносторонний треугольник (все стороны равны, все углы равны 60);
//прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
//квадрат (все стороны равны, все углы равны 90);
//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
//ромб (все стороны равны, углы A,C и B,D попарно равны).
//Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов, но извне вы не должны быть способны изменить длины сторон и углы.
//
//Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям. Например, нельзя создать квадрат с разными углами. Геометрические соотношения проверять не нужно. Например, сумма углов в треугольнике может быть не равна 180.
//
//Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о длинах её сторон и величине её углов. Значения используйте произвольные.
//
//Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.
//
//Для вывода информации о фигуре создайте функцию print_info, которая будет принимать в качестве аргумента указатель на базовый класс фигуры.
//
//Пример работы программы
//
//Консоль
//
//Треугольник:
//Стороны: a=10 b=20 c=30
//Углы: A=50 B=60 C=70
//
//Прямоугольный треугольник:
//Стороны: a=10 b=20 c=30
//Углы: A=50 B=60 C=90
//
//Равнобедренный треугольник:
//Стороны: a=10 b=20 c=10
//Углы: A=50 B=60 C=50
//
//Равносторонний треугольник:
//Стороны: a=30 b=30 c=30
//Углы: A=60 B=60 C=60
//
//Четырёхугольник:
//Стороны: a=10 b=20 c=30 d=40
//Углы: A=50 B=60 C=70 D=80
//
//Прямоугольник:
//Стороны: a=10 b=20 c=10 d=20
//Углы: A=90 B=90 C=90 D=90
//
//Квадрат:
//Стороны: a=20 b=20 c=20 d=20
//Углы: A=90 B=90 C=90 D=90
//
//Параллелограмм:
//Стороны: a=20 b=30 c=20 d=30
//Углы: A=30 B=40 C=30 D=40
//
//Ромб:
//Стороны: a=30 b=30 c=30 d=30
//Углы: A=30 B=40 C=30 D=40