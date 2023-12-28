#include <iostream>

class Figure{
public:
	Figure(){
		this->sides_count = 0;
		this->name = "Фигура";
	}
  virtual ~Figure() {}
	int get_sides_count() {
		return this->sides_count;
	}
	std::string get_name() {
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
	Triangle():Figure(3,"Треугольник"){
	    this->a = 10;
	    this->b = 20;
	    this->c = 30;
	    this->A = 50;
	    this->B = 60;
	    this->C = 70;
	}
	int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
    int getCapitalA() const { return A; }
    int getCapitalB() const { return B; }
    int getCapitalC() const { return C; }
protected:
	double a;
	double b;
	double c;
	double A;
	double B;
	double C;
	Triangle(std::string name, double a, double b, double c, double A, double B, double C): Figure(3, name ) {
	    this->a = a;
	    this->b = b;
	    this->c = c;
	    this->A = A;
	    this->B = B;
	    this->C = C;
	}
};
class Quadrangle: public Figure{
public:
	Quadrangle():Figure(4,"Четырехугольник"){
	    this->a = 10;
	    this->b = 20;
	    this->c = 30;
	    this->d = 40;
	    this->A = 50;
	    this->B = 60;
	    this->C = 70;
	    this->D = 80;
	}
	int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
    int getD() const { return d; }
    int getCapitalA() const { return A; }
    int getCapitalB() const { return B; }
    int getCapitalC() const { return C; }
     int getCapitalD() const { return D; }
protected:
	double a;
	double b;
	double c;
	double d;
	double A;
	double B;
	double C;
	double D;
	Quadrangle(std::string name, double a, double b, double c,double d, double A, double B, double C,double D): Figure(4, name ) {
	    this->a = a;
	    this->b = b;
	    this->c = c;
	    this->d = d;
	    this->A = A;
	    this->B = B;
	    this->C = C;
	    this->D = D;
	};

};
class RightTriangle: public Triangle{
public:
	RightTriangle():Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 60,90) {}
};
class IsoscelesTriangle: public Triangle{
public:
	IsoscelesTriangle():Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 60,50) {}
};
class EquilateralTriangle: public Triangle{
public:
	EquilateralTriangle():Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60,60) {}
};
class EquilateralQuadrangle: public Quadrangle{
    public:
        EquilateralQuadrangle():Quadrangle("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}
    protected:
        EquilateralQuadrangle(std::string name, double a ,double A):Quadrangle(name, a,a,a,a,A,A,A,A) {}
    
};
class Square: public EquilateralQuadrangle{
    public:
        Square(): EquilateralQuadrangle("Квадрат", 10 , 90){}
};
class Parallelogram: public Quadrangle{
    public:
        Parallelogram():Quadrangle("Парралеллограмм", 20, 30, 20, 30, 30, 40, 30, 40) {}
};
class Rhombus: public Quadrangle{
    public:
        Rhombus():Quadrangle("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {}
};


void print_info( Figure* fig) {
	if (fig->get_sides_count() == 3) {
		std::cout << fig->get_name() << ": \n"
		<< "Стороны: a = " << dynamic_cast<const Triangle*>(fig)->getA()
		<< " b = " << dynamic_cast<const Triangle*>(fig)->getB()
		<< " c = " << dynamic_cast<const Triangle*>(fig)->getC() << "\n";
		std::cout << "Углы: A = " << dynamic_cast<const Triangle*>(fig)->getCapitalA()
		<< " B = " << dynamic_cast<const Triangle*>(fig)->getCapitalB()
		<< " C = " << dynamic_cast<const Triangle*>(fig)->getCapitalC() << "\n\n";
	} else if (fig->get_sides_count() == 4) {
		std::cout << fig->get_name() << ": \n"
		<< "Стороны: a = " << dynamic_cast<const Quadrangle*>(fig)->getA()
		<< " b = " << dynamic_cast<const Quadrangle*>(fig)->getB()
		<< " c = " << dynamic_cast<const Quadrangle*>(fig)->getC()
		<< " d = " << dynamic_cast<const Quadrangle*>(fig)->getD() << "\n";
		std::cout << "Углы: A = " << dynamic_cast<const Quadrangle*>(fig)->getCapitalA()
		<< " B = " << dynamic_cast<const Quadrangle*>(fig)->getCapitalB()
		<< " C = " << dynamic_cast<const Quadrangle*>(fig)->getCapitalC()
		<< " D = " << dynamic_cast<const Quadrangle*>(fig)->getCapitalD() << "\n\n";
	} else {
		std::cout << "Неправильное количество углов\n";
	}
}



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