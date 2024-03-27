#include <iostream>
#include <cmath>

int main(){
    std::vector<double> angles ={30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180};
    std::vector<std::function<void(double)>> functions;
    std::function<void(double)> find_sin = [](double angl){
        std::cout<<" sin: "<< (sin (angl));
    };
    functions.push_back(find_sin);
    std::function<void(double)> find_cos = [](double angl){
        std::cout<<" cos: "<< (cos (angl));
    };
    functions.push_back(find_cos);
    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}

//Задача 3. Операции над углами
//
//        Описание
//
//Иногда бывает необходимо сохранить созданные лямбда-функции.
// Для этого есть тип std::function . В этой задаче вам дан массив углов.
// Нужно вывести их синус и косинус. Сделать это необходимо так,
// чтобы при необходимости произвести новые операции с углами, например,
// если захотим посчитать тангенсы, не изменять код вывода.
//
//for (const auto& angle : angles) {
//std::cout << angle << ": ";
//for (const auto& function : functions)
//function(angle);
//std::cout << std::endl;
//}
//Пример логической работы программы
//
//[Входные данные]: 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180
// перевод из градусов в радианы
//[Выходные данные]:
//0.523599: sin: 0.5 cos: 0.866025
//1.0472: sin: 0.866025 cos: 0.5
//1.5708: sin: 1 cos: 2.67949e-08