#include <iostream>



template <class T>
class vector{
	
private:
	int size = 0;
	int capasity = 1;
	T* vecPtr;
public:
	//пушбек
	void push_back(T num){
		if(size < capasity){
			vecPtr[size] = num;
		}else {
			capasity *=2;
			T* newVec = new T[capasity];
			for(int i = 0; i < size; i++ ){
				newVec[i] = vecPtr[i];
			}
			delete[]vecPtr;
			vecPtr = newVec;
			vecPtr[size] = num;
		}
		size++;
	}
	
	//конструктор копирования
	vector(vector<T>& other){
		vecPtr = new T[other.capasity];
		for (int i = 0; i < other.sizeGetter(); i++) {
			push_back(other.vecPtr[i]);
		}
	}
	
	//стандартный конструктор
	vector(){
		vecPtr = new T[capasity];
	}
	
	//деструктор
	~vector(){
//		for (int i = 0; i < size; i++) {
//			delete[] vecPtr[i];
//		}
		delete[] vecPtr;
	}
	
	// at
	T& at(int index){
		if(size <= index || index < 0) throw std::string("Нет такого инекса");
		return vecPtr[index];
	}
	//size getter
	
	int sizeGetter(){
		return this->size;
	}
	int capasityGetter(){
		return this->capasity;
	}
	
	
};


int main(int argc, char *argv[]) {
	try {
		vector<char> vect;
		vect.push_back('a');
		vect.push_back('s');
		vect.push_back('d');
		vect.push_back('f');
		vect.push_back('g');
		vect.push_back('h');
		vector<char> newVec(vect);
		std::cout <<"size: "<< newVec.sizeGetter()<<std::endl;
		std::cout <<"capasity: "<< newVec.capasityGetter()<<std::endl;
		for(int i = 0; i < newVec.sizeGetter(); i ++){
			std::cout << i+1 <<" "<< newVec.at(i)<<"\n";
		}
	} catch (std::string error) {
		std::cout << error;
	}
}



//Задача 3*. Аналог std::vector
//
//Описание
//
//Для лучшего понимания работы std::vector в этом задании вам нужно написать собственную шаблонную упрощённую реализацию std::vector.
//
//У вашего контейнера должны работать функции:
//
//at(int index) — доступ к элементу контейнера по индексу;
//push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
//size () — количество элементов в контейнере;
//capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.

//конструктор копирования оператор присваивания деструктор