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




