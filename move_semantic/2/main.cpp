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
    
    big_integer(big_integer&& other) noexcept: number(std::move(other.number)){};
    
    big_integer& operator=(big_integer&& other) noexcept{
        if (this != &other) {
            number = std::move(other.number);
        }
        return *this;
    }
    ~big_integer()= default;
    
    big_integer operator+(const big_integer& other) const{
        int max_str_size = number.size() > other.number.size() ? number.size(): other.number.size();
        std::string result(max_str_size, '0');   
        std::string number1 = std::string(max_str_size - number.length(), '0') + number;
        std::string number2 = std::string(max_str_size - other.number.length(), '0') + other.number;
        for (int next = 0, i = max_str_size - 1; i >= 0; i--) {
            int sum = (number1[i] - '0') + (number2[i] - '0') + next;
            int mod = sum % 10;
            int div = sum / 10;
            result[i] = mod + '0';;
            next = div;
        }
        return big_integer(std::move(result));
    }

    std::string operator*(int integer){
        std::string result;
        int carry = 0;
        for (int i = number.size() - 1; i >= 0; --i) {
            int digit = number[i] - '0';
            int product = digit * integer + carry;
            result = std::to_string(product % 10) + result;
            carry = product / 10;
        }
        while (carry) {
            result = std::to_string(carry % 10) + result;
            carry /= 10;
        }return result;
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
    auto result = number1 + number2;
    std::cout << result<<"\n";
    std::cout << number2 * 23<<"\n";
    
    auto d = number1 + number2;
    std::cout << d;

    return 0;
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