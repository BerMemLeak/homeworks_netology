//
// Created by user on 23.04.2024.
//
#include <iostream>
#include <string>
#include <utility>

class big_integer{
private:
    std::string number;
public:
    big_integer(std::string old_num){
        number = std::move(old_num);
    }//если передаем по значению

    big_integer(std::string& old_num){
        number = std::move(old_num);
    }//если передаем по ссылке

    big_integer& operator=(big_integer& other){
        if (this != &other) {
            number = std::move(other.number);// так как оператор присваивания - функция класса,
            // то она имеет доступ и к other
        }
        return *this;
    }
    big_integer& operator+(big_integer& other){

    }

    big_integer& operator*(int integer){

    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& bi) {
        os << bi.number;
        return os;
    }


};


int main (){
    std::string a = "11232132131";
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    number1 = number2;
    std::cout << number1;
}
//Задача 2. Большие числа
//
//Описание
//
//        Вам нужно реализовать класс для работы с большими числами, которые
//        не помещаются в стандартные типы данных.
//
//Для этого класса нужно определить методы:
//
//конструктор перемещения;
//перемещающий оператор присваивания;
//оператор сложения двух больших чисел;
//оператор умножения на число.
//Для реализации этого класса можно воспользоваться std::string или std::vector.
//
//Пример правильной работы программы
//
//auto number1 = big_integer("114575");
//auto number2 = big_integer("78524");
//auto result = number1 + number2;
//std::cout << result; // 193099