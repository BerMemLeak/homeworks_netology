#include <iostream>

template<class T>
class unique_ptr{
private:
    T* ptr = nullptr;
    
public:
    unique_ptr(T* &ptr1){
            ptr = ptr1;
            ptr1 = nullptr;
    };
    unique_ptr(const unique_ptr<T>& other) = delete;
    unique_ptr<T>& operator=(const unique_ptr<T>& other) = delete;
    
    T& operator*(){
        return *ptr;
    }
    ~unique_ptr(){
        if (ptr != nullptr) {
            delete ptr;
        }
    };
    T* release(){
        auto newPtr = this->ptr;
        ptr = nullptr;
        return newPtr;
    }
};

int main(int argc, char *argv[]) {
    int* ptrr = new int(5);
    unique_ptr<int> asd(ptrr);
    std::cout <<*asd << std::endl;
    int* j = asd.release();
    delete j;


    return 0;
}


//Задача 3*. std::unique_ptr своими руками
//
//        Описание
//
//Нужно создать упрощённый аналог std::unique_ptr.
//
//В шаблонном классе должны быть реализованы функции:
//
//Конструктор, принимающий сырой указатель.
//Перегружен оператор * для получения объекта.
//Запрещены оператор присваивания и конструктор копирования.
//Метод release, который освобождает владение и возвращает сырой указатель.
//Деструктор.