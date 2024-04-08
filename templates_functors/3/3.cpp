#include <iostream>

using namespace std;

class mod3{
private:
	int* arr;
	int size;
	int sum ;
	int count ;
public:
	mod3(int* arr,int size): arr(arr), size(size),sum(0), count(0){};
	void operator()(){
		for (int i = 0; i < size; i++) {
			if (arr[i] % 3 == 0) {
				this->count++;
				this->sum+=arr[i];
			}
		}
	}
	int get_sum(){return this->sum;}
	int get_count(){return this->count;}
};



int main(int argc, char *argv[]) {
	int arr[] = {4, 1, 3, 6, 25, 54};
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout<<std::endl;
	
	mod3 arr1(arr,sizeof(arr)/sizeof(arr[0]));
	arr1();
	std::cout << "get_sum() = "<< arr1.get_sum()<< std::endl;
	std::cout << "get_count() = "<< arr1.get_count();

	

}

//Задача 3. Счётчик чисел
//
//Описание
//
//В этом задании вам нужно реализовать функтор, который подсчитывает сумму и количество чисел, делящихся на 3.
//
//Должны быть реализованы 2 функции:
//
//get_sum()
//get_count()
//Пример правильной работы программы
//
//[IN]: 4 1 3 6 25 54
//[OUT]: get_sum() = 63
//[OUT]: get_count() = 3