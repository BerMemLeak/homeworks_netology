#include <iostream>

class smart_array{
public:
	smart_array(int len){
		this->len = len;
		this->arrBegin = new int[len];
	};
	~smart_array(){
		delete[] arrBegin;
		};
	void add_element(int num){
		if(arr_count < len){
			this->arrBegin[arr_count ]= num;
			this->arr_count++;
		}//дописать логику расширения массива
		else {
			int* newArr = new int[len*2];
			for (int u = 0; u < len ; u ++) {
				newArr[u] = arrBegin[u];
			}
				len*=2;
				delete [] arrBegin;
				this->arrBegin = newArr;
				this->arrBegin[arr_count ]= num;
				this->arr_count++;
		
		}
	}
	int get_element(int index){
	if (index > arr_count - 1) {
			throw "Нет элемента по этому индексу";
		}
		return *(this->arrBegin + index);
	}
	void cout_mass(){
		for (int i = 0; i < len; i++) {
			std::cout << arrBegin[i] << ' ';
		}
	}
private:
	int len;
	int* arrBegin;
	int arr_count = 0;
};
int main(int argc, char *argv[]) {
	try {
		

		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.cout_mass();
		std::cout <<"\n"<<arr.get_element(7) << std::endl;
	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
	}
}



//Задача 1. Умный массив
//
//Описание
//
//Вам нужно реализовать умный массив для данных типа int в духе идиомы RAII, который сам управляет своей памятью: самостоятельно выделяет её при создании и очищает, когда объект данного класса не используется.
//
//Должны быть реализованы следующие функции:
//
//Конструктор, принмающий количество элементов, которое будет хранить массив.
//Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
//Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
//Деструктор.