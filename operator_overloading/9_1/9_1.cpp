#include <iostream>

class Fraction
{
private:
	double numerator_;
	double denominator_;
public:
	Fraction(double numerator, double denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}


	bool operator< (Fraction& other){
		return (this->numerator_/this->denominator_) < (other.numerator_/other.denominator_);
	}
	bool operator> (Fraction& other){
		return (this->numerator_/this->denominator_) > (other.numerator_/other.denominator_);	}
	
	bool operator== (Fraction& other){
		return (!operator<(other) && !operator>(other));	}
	
	bool operator!=(Fraction& other){
		return (operator<(other) || operator>(other));	}
	
	bool operator<=(Fraction& other){
		return (operator< (other)) || operator==(other);	}
	
	bool operator>=(Fraction& other){
		return (operator> (other)) || operator==(other);	}
	

};

int main()
{
	Fraction f1(31, 3);
	Fraction f2(1, 1);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}

//Ваша задача — дописать класс Fraction так, чтобы программа компилировалась и работала корректно.
//
//Пример работы программы
//
//Консоль
//
//f1 not == f2
//f1 != f2
//f1 not < f2
//f1 > f2
//f1 not <= f2
//f1 >= f2