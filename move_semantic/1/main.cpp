//
// Created by user on 23.04.2024.
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
template<class T>
void move_vectors(std::vector<T>& a, std::vector<T>& b){
    b = std::move(a);
};

template<class T>
void print(const std::vector<T>& b){
    for (auto &it:b) {
        std::cout << it <<" ";
    }
};

int main(){
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors( one, two);
    print(two);
    return 0;
}

//Задача 1. Перемещение объектов
//
//Описание
//
//Вам нужно реализовать шаблонную функцию, которая перемещает
//содержимое одного std::vector в другой.