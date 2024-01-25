#include "Triangle.h" 
#include "../../Errors/MyError.h"
Triangle::Triangle():Figure(3,"Треугольник"){
 this->a = 10;
 this->b = 20;
 this->c = 30;
 this->A = 90;
 this->B = 45;
 this->C = 45;
    if(((A + B + C )!=180) || sides_count != 3)
    {
        throw MyError("Ошибка создания треугольника. Причина: сумма углов не равна 180 или количество сторон не 3\n\n");
    }
}
double Triangle::getA()   { return a; }
double Triangle::getB()   { return b; }
double Triangle::getC()   { return c; }
double Triangle::getCapitalA()  { return A; }
double Triangle::getCapitalB()  { return B; }
double Triangle::getCapitalC()  { return C; }
Triangle::Triangle(const std::string& name, double a, double b, double c, double A, double B, double C): Figure(3, name ) {

 this->a = a;
 this->b = b;
 this->c = c;
 this->A = A;
 this->B = B;
 this->C = C;

}