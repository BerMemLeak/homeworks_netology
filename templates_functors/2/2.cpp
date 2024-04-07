#include <iostream>

template <class T>
class Twrapper{
private:
	int n;
	T* arr;
	int i;
public:
	Twrapper(T* arr, int n) :n(n) , arr(arr){};
	T& operator[](int i){
		if (i < 0 || i >= n) {
			throw std::runtime_error("нет такого индекса");
		}
		return arr[i];
	}
	T&  operator = (T b){
		arr[i] = b;
	};
};


template <class T>
class table{
public:
	table(T rows, T cols){
		this->rows = rows;
		this->cols = cols;
		this->arrPtr = new int* [rows];
		for (int i = 0; i < rows; i++) {
			arrPtr[i] = new int [cols];
		}
	}
	~table(){
		for (int i = 0; i < rows; i++) {
			delete [] arrPtr[i];
		}
		delete [] arrPtr;
	}
	Twrapper<T> operator[](int i){
		this->i = i;
		if (i < 0 || i >= rows) {
			throw std::runtime_error(" нет такого индекса");
		}
		Twrapper<T> result(arrPtr[i],cols);
		return result;
	}
	Twrapper<T>&  operator = (T b){
		Twrapper<T> result(arrPtr[i],cols);
		return result;
	};
private:
	int i;
	int rows;
	int cols;
	T** arrPtr;
	
};

int main(int argc, char *argv[]) {
	try {
		auto test = table<int>(2, 3);
		test[0][0] = 4; // Изменение индекса с 7 на 0
		std::cout << test[0][0]; // Выведет 4
	} catch (std::runtime_error& ex) {
		std::cout << ex.what();
	}
}


//Описание
//
//Нужно написать шаблонный класс для двумерного массива (таблицы). Все ячейки таблицы имеют один и тот же тип данных T.
//
//Требования к классу:
//
//Должен быть конструктор, получающий на входе два целых числа — количество строк и столбцов соответственно.
//Должны быть константная и неконстантная версии оператора [], возвращающего массив, к которому снова можно применить оператор [].
//Нужно, чтобы работали конструкции вида:
//* cout << table[i][j]; * table[i][j] = value;.
//
//Должна быть константная функция Size, возвращающая размер таблицы.
//Пример правильной работы программы
//
//auto test = table<int>(2, 3);
//test[0][0] = 4;
//std::cout << test[0][0]; // выводит 4