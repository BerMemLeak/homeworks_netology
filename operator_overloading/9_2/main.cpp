#include <iostream>
#include "error/error.h"

class Fraction
{
private:
	double numerator_;
	double denominator_;
public:
	Fraction(double num, double den)
	{
		if(den == 0){throw error("В знаменателе ноль. Я не умею делить на ноль(  ");
		}else{
			numerator_ = num;
			denominator_ = den;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
		os << fraction.numerator_ << "/" << fraction.denominator_;
		return os;}
	int greatestCommonDivisor(int a, int b) const {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	
	Fraction operator+ (Fraction& other){
		double fullNum = (this->numerator_* other.denominator_) + (other.numerator_ * this->denominator_);
		double fullDen = (this->denominator_* other.denominator_) ;
		int gcd = greatestCommonDivisor(fullNum, fullDen);
		return Fraction(fullNum/gcd,fullDen/gcd);
	}
	Fraction operator- (Fraction& other){
		double fullNum = (this->numerator_* other.denominator_) - (other.numerator_ * this->denominator_);
		double fullDen = (this->denominator_* other.denominator_);
		int gcd = greatestCommonDivisor(fullNum, fullDen);
		return Fraction(fullNum/gcd,fullDen/gcd);
	}
	Fraction operator* (Fraction& other){
		double fullNum = this->numerator_*  other.numerator_ ;
		double fullDen = (this->denominator_* other.denominator_);
		int gcd = greatestCommonDivisor(fullNum, fullDen);
		return Fraction(fullNum/gcd,fullDen/gcd);
	}
	Fraction operator/ (Fraction& other){
		double fullNum = this->numerator_*  other.denominator_ ;
		double fullDen = (this->denominator_* other.numerator_);
		int gcd = greatestCommonDivisor(fullNum, fullDen);
		return Fraction(fullNum/gcd,fullDen/gcd);
	}
	//вот тут еще функции
	

};

int main()
{
	double numerator1 = 0;
	double delimetr1 = 0;
	double numerator2 = 0;
	double delimetr2 = 0;
	std::cout << "\nВведите числитель дроби 1: ";
	std::cin >> numerator1;
	std::cout << "\nВведите знаменатель дроби 1: "; 
	std::cin >> delimetr1;
	std::cout << "\nВведите числитель дроби 2: ";
	std::cin >> numerator2;
	std::cout << "\nВведите знаменатель дроби 2: "; 
	std::cin >> delimetr2;
	try {
		Fraction f1(numerator1, delimetr1);
		Fraction f2(numerator2, delimetr2);
		std::cout << f1 <<" + "<< f2 << " = "<< f1 + f2 <<"\n";
		std::cout << f1 <<" - "<< f2 << " = "<< f1 - f2 <<"\n";
		std::cout << f1 <<" * "<< f2 << " = "<< f1 * f2 <<"\n";
		std::cout << f1 <<" / "<< f2 << " = "<< f1 / f2 <<"\n";
		// вот тут еще выводы
	} catch (error& mes) {
		std::cout << mes.what();
	}
	



	return 0;
}

//Введите числитель дроби 1: 3
//Введите знаменатель дроби 1: 4
//Введите числитель дроби 2: 4
//Введите знаменатель дроби 2: 5
//3/4 + 4/5 = 31/20
//3/4 - 4/5 = -1/20
//3/4 * 4/5 = 3/5
//3/4 / 4/5 = 15/16
//++3/4 * 4/5 = 7/5
//Значение дроби 1 = 7/4
//7/4-- * 4/5 = 7/5
//Значени дроби 1 = 3/4