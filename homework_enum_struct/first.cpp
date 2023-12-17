#include <iostream>

enum class Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

std::string getMonthName(Months month) {
    switch (month) {
        case Months::January: return "Январь";
        case Months::February: return "Февраль";
        case Months::March: return "Март";
        case Months::April: return "Апрель";
        case Months::May: return "Май";
        case Months::June: return "Июнь";
        case Months::July: return "Июль";
        case Months::August: return "Август";
        case Months::September: return "Сентябрь";
        case Months::October: return "Октябрь";
        case Months::November: return "Ноябрь";
        case Months::December: return "Декабрь";
        default: return "Неправильный номер!";
    }
}

int main() {
    int numOfMonth = 0;
    
    while (true) {
        std::cout << "Введите номер месяца: ";
        std::cin >> numOfMonth;
        
        if (numOfMonth == 0) {
            break;
        }
        
        Months month = static_cast<Months>(numOfMonth);
        std::string monthName = getMonthName(month);
        std::cout << monthName << std::endl;
    }
    
    std::cout << "До свидания" << std::endl;

    return 0;
}

//
//Задача 1. Месяцы
//
//Описание
//
//Напишите программу, которая спрашивает у пользователя номер месяца и выводит на экран название месяца, введённого пользователем.
//
//Если пользователь ввёл некорректный номер месяца, сообщите ему об этом.
//
//Спрашивайте пользователя до тех пор, пока он не введёт 0.
//
//Для решения задачи воспользуйтесь перечислением.
//
//Пример работы программы
//
//Введите номер месяца: 1
//Январь
//Введите номер месяца: 7
//Июль
//Введите номер месяца: 13
//Неправильный номер!
//Введите номер месяца: 0
//До свидания