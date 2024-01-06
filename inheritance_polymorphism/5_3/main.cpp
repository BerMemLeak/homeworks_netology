#include <iostream>

class Figure{
public:
	Figure(){
		this->sides_count = 0;
		this->name = "Фигура";
	}
  virtual ~Figure() {}// деструктор базового класса
	int get_sides_count() {
		return this->sides_count;
	}
	std::string get_name() {
		return this->name;
	}

	
	virtual void print_info(){
		std::cout <<this->name << ": \n";
		check()? std::cout <<"Правильная \n": std::cout <<"Неправильная \n";
		std::cout << "Количество сторон: "<<this->sides_count << ": \n\n";
	};
	
protected:
	Figure(int count, std::string name){
		this->sides_count = count;
		this->name = name;
	}
	virtual bool check(){
		return this->sides_count == 0;
		
	};
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
	void print_info() override {
		std::cout <<this->name << ": \n";
		check()? std::cout <<"Правильная \n": std::cout <<"Неправильная \n";
		std::cout << "Количество сторон: "<<this->sides_count << " \n";
		std::cout << "Стороны: a = " << getA()
		<< " b = " << getB()
		<< " c = " << getC() << "\n";
		std::cout << "Углы: A = "<< getCapitalA()
		<< " B = " << getCapitalB()
		<< " C = " << getCapitalC() << "\n\n";
	};
protected:
	bool check() override {
		if (this->sides_count == 3 && A + B + C == 180) {
			return true;
		}else {
			return false;
		}
		
	};
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
	void print_info() override {
		std::cout <<this->name << ": \n";
		check()? std::cout <<"Правильный \n": std::cout <<"Неправильный \n";
		std::cout << "Количество сторон: "<<this->sides_count << " \n";
		std::cout << "Стороны: a = " << getA()
		<< " b = " << getB()
		<< " c = " << getC() 
		<< " d = " << getD() << "\n";
		std::cout << "Углы: A = "<< getCapitalA()
		<< " B = " << getCapitalB()
		<< " C = " << getCapitalC() 
		<< " D = " << getCapitalD() << "\n\n";
	};
protected:
	bool check() override {
		if (this->sides_count == 4 && A + B + C +D == 360) {
			return true;
		}else {
			return false;
		}
		
	};
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
	RightTriangle():Triangle("Прямоугольный треугольник", 10, 20, 30, 50, 40,90) {}
protected:
	bool check() override {
		if (this->sides_count == 3 && A + B + C == 180 && (C == 90)) {
			return true;
		}else {
			return false;
		}
		
	};
};

class IsoscelesTriangle: public Triangle{
public:
	IsoscelesTriangle():Triangle("Равнобедренный треугольник", 10, 20, 10, 50, 80,50) {}
protected:
	bool check() override {
		if (this->sides_count == 3 && A + B + C == 180 && a == c && A == C ){
			return true;
		}else {
			return false;
		}
		
	};
};

class EquilateralTriangle: public Triangle{
public:
	EquilateralTriangle():Triangle("Равносторонний треугольник", 30, 30, 30, 60, 60,60) {}
protected:
	bool check() override {
		if (this->sides_count == 3 && A + B + C == 180 && a == c && c == b && A == 60 && B == 60 && C == 60 ){
			return true;
		}else {
			return false;
		}
		
	};
};

class EquilateralQuadrangle: public Quadrangle{
    public:
        EquilateralQuadrangle():Quadrangle("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90) {}
protected:
	bool check() override {
		if (this->sides_count == 4 && A == 90 && B == 90 && C == 90 && D == 90 && a==c && b ==d) {
			return true;
		}else {
			return false;
		}
		
	};
	EquilateralQuadrangle(std::string name, double a ,double A):Quadrangle(name, a,a,a,a,A,A,A,A) {}
    
};

class Square: public EquilateralQuadrangle{
public:
	Square(): EquilateralQuadrangle("Квадрат", 10 , 90){}
protected:
	bool check() override {
		if (this->sides_count == 4 && A == 90 && B == 90 && C == 90 && D == 90 && a==c && a ==d && a == b) {
			return true;
		}else {
			return false;
		}
		
	};
};

class Parallelogram: public Quadrangle{
public:
Parallelogram():Quadrangle("Парралеллограмм", 20, 30, 20, 30, 30, 40, 30, 40) {}
protected:
	bool check() override {
		if (this->sides_count == 4 && A == C && B ==D && a==c && b ==d ) {
			return true;
		}else {
			return false;
		}
		
	};
};

class Rhombus: public Quadrangle{
public:
	Rhombus():Quadrangle("Ромб", 30, 30, 30, 30, 30, 40, 30, 40) {}
protected:
	bool check() override {
		if (this->sides_count == 4 && A == C && B ==D && a==c && a ==d && a == b) {
			return true;
		}else {
			return false;
		}
		
	};
};

int main(int argc, char *argv[]) {
	
	Figure fig;
	fig.print_info();	
	
	Triangle tri;
	Figure* g = &tri;
	g->print_info();

	RightTriangle q;
	Figure* k = &q;
	k->print_info();
	
	IsoscelesTriangle w;
	Figure* v = &w;
	v->print_info();
	
	EquilateralTriangle t;
	Figure* e = &t;
	e->print_info();
	
	Quadrangle qua;
	Figure* kl = &qua;
	kl->print_info();
	
	EquilateralQuadrangle r;
	Figure* kg = &r;
	kg->print_info();
	
	Square rasd;
	Figure* asd = &rasd;
	asd->print_info();
	
	Parallelogram a;
	Figure* asffd = &a;
	asffd->print_info();
	
	Rhombus d;
	Figure* das = &d;
	das->print_info();
	return 0;
}

//
//Задача 3. Фигуры. Методы
//
//В этом задании вы добавите в вашу иерархию классов больше функциональности.
//
//Теперь ваши фигуры должны уметь немного больше:
//
//выводить информацию о себе;
//проверять правильность своих данных.
//Ваши фигуры:
//
//фигура (количество сторон равно 0);
//треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
//прямоугольный треугольник (угол C всегда равен 90);
//равнобедренный треугольник (стороны a и c равны, углы A и C равны);
//равносторонний треугольник (все стороны равны, все углы равны 60);
//четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
//прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
//квадрат (все стороны равны, все углы равны 90);
//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
//ромб (все стороны равны, углы A,C и B,D попарно равны).
//Вы должны иметь возможность попросить фигуру вывести информацию о себе на консоль, а также узнать, является ли фигура правильной, то есть выполняются ли условия, указанные в списке выше.
//
//Информация о фигуре включает в себя:
//
//название фигуры;
//количество сторон;
//длины её сторон, если есть;
//величины её углов, если есть;
//является ли фигура правильной.
//Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонструйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о фигурах.
//
//Реализуйте методы вывода на консоль и проверки правильности фигуры с помощью виртуальных функций и переопределений. Используйте вызов базовой версии метода.
//
//Ваша задача — работать с экземплярами дочерних классов полиморфно, то есть с помощью указателя на базовый класс.
//
//Пример работы программы
//
//Консоль
//
//Фигура:
//Правильная
//Количество сторон: 0
//
//Треугольник:
//Правильная
//Количество сторон: 3
//Стороны: a=10 b=20 c=30
//Углы: A=50 B=60 C=70
//
//Прямоугольный треугольник:
//Неправильная
//Количество сторон: 3
//Стороны: a=10 b=20 c=30
//Углы: A=50 B=60 C=90
//
//Прямоугольный треугольник:
//Правильная
//Количество сторон: 3
//Стороны: a=10 b=20 c=30
//Углы: A=50 B=40 C=90
//
//Равнобедренный треугольник:
//Неправильная
//Количество сторон: 3
//Стороны: a=10 b=20 c=10
//Углы: A=50 B=60 C=50
//
//Равносторонний треугольник:
//Правильная
//Количество сторон: 3
//Стороны: a=30 b=30 c=30
//Углы: A=60 B=60 C=60
//
//Четырёхугольник:
//Неправильная
//Количество сторон: 4
//Стороны: a=10 b=20 c=30 d=40
//Углы: A=50 B=60 C=70 D=80
//
//Прямоугольник:
//Правильная
//Количество сторон: 4
//Стороны: a=10 b=20 c=10 d=20
//Углы: A=90 B=90 C=90 D=90
//
//Квадрат:
//Правильная
//Количество сторон: 4
//Стороны: a=20 b=20 c=20 d=20
//Углы: A=90 B=90 C=90 D=90
//
//Параллелограмм:
//Неправильная
//Количество сторон: 4
//Стороны: a=20 b=30 c=20 d=30
//Углы: A=30 B=40 C=30 D=40
//
//Ромб:
//Неправильная
//Количество сторон: 4
//Стороны: a=30 b=30 c=30 d=30
//Углы: A=30 B=40 C=30 D=40