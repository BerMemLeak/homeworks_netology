#include <iostream>

using namespace std;

template <class T>
void sqrt_func(T& t){
	t = (t)*(t);
}
template<class T>
void sqrt_func(std::vector<T>& t){
	for (int& i : t) {
		i = i*i;
	}	
}

int main(int argc, char *argv[]) {
	int a = 5;
	std::vector<int> v = {-1,5,2,23};
	sqrt_func(a);
	sqrt_func(v);
	std::cout<< "вектор: ";
	for (int i : v) {
		std::cout << i << " ";
	}
	std::cout<< "\nчисло: "<<a;
}

//Нужно реализовать шаблонную функцию возведения в квадрат, которая работает не только с простыми числами, но и с векторами. Для этого создайте две реализации шаблонной функции.