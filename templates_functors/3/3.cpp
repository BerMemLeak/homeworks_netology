#include <iostream>

using namespace std;

class mod3{
private:
	int* arr;
	int size;
public:
	mod3(int* arr,int size): arr(arr), size(size){};
	int operator()(){
		int result = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] % 3 == 0) {
				result++;
			}
		}
		
		return result;
	}
};
class Sum_mod3{
private:
	int* arr;
	int size;
public:
	Sum_mod3(int* arr,int size): arr(arr), size(size){};
	int operator()(){
		int result = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] % 3 == 0) {
				result+= arr[i];
			}
		}
		
		return result;
	}
};


int main(int argc, char *argv[]) {
	int arr[] = {4, 1, 3, 6, 25, 54};
	for (int i = 0; i < sizeof(arr)/arr[0]; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout<<std::endl;
	
	mod3 arr1(arr,sizeof(arr)/arr[0]);
	Sum_mod3 arr2(arr,sizeof(arr)/arr[0]);
	
	std::cout << "get_sum() = "<< arr2()<< std::endl;
	std::cout << "get_count() = "<< arr1();

	

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