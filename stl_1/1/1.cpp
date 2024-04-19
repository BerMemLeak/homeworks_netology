#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>


bool compare(std::pair<char, int>& a, std::pair<char, int>& b) {
    return a.second > b.second; 
}

std::string sortByFrequency(const std::string& str) {
    std::unordered_map<char, int> freqMap;
    for (char c : str) {
        freqMap[c]++;
    }
    
    std::vector<std::pair<char, int>> vec(freqMap.begin(), freqMap.end());
    
    std::sort(vec.begin(), vec.end(), compare);
    
    std::string sortedStr;
    for (const auto& p : vec) {
        sortedStr.append(p.second, p.first);
    }
    return sortedStr;
}

int main(int argc, char* argv[]) {
    
    std::string str;
    std::getline(std::cin, str);
    std::string sorted = sortByFrequency(str);
    std::cout << "Отсортированная строка: " << sorted << std::endl;
    if (!sorted.empty()) {
        char currentChar = sorted[0];
        int count = 1;
        for (char c : sorted.substr(1)) { // начинаем со второго символа
            if (c == currentChar) {
                count++;
            }
            else {
                std::cout << "\n" << currentChar << ": " << count;
                currentChar = c;
                count = 1;
            }
        }
        // Вывод частоты для последнего символа
        std::cout << "\n" << currentChar << ": " << count << std::endl;
    }
    return 0;
}


//Задача 1. Частота символов
//
//Описание
//
//Нужно посчитать, сколько раз каждый символ встречается в заданном тексте, и отсортировать по убыванию частоты.
//
//Пример правильной работы программы
//
//[IN]: Hello world!!
//[OUT]: 
//l: 3
//o: 2
//!: 2
//: 1
//H: 1
//e: 1
//d: 1
//w: 1
//r: 1