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
	smart_array& operator=(const smart_array& b) {
		if (this != &b) {
			delete[] arrBegin; 
			len = b.len;
			arrBegin = new int[len];
			for (int i = 0; i < len; i++) {
				arrBegin[i] = b.arrBegin[i]; 
			}
		}
		return *this;
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
		
		smart_array new_array(2);
		new_array.add_element(44); 
		new_array.add_element(34);
		
		arr = new_array;
		arr.cout_mass();
		std::cout << " \n";
		new_array.cout_mass();
		std::cout << " \n" << &arr;
		std::cout << " \n" << &new_array;

	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
	}
}
//
//Задача 2. Копирование умных массивов
//
//Описание
//
//В этом задании вам нужно поработать с классом умных массивов, который вы реализовали в предыдущем задании. Сначала попробуйте создать два экземпляра вашего класса с различными элементами и присвоить один другому.