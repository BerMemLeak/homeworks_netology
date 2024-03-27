#include <iostream>
void printRes(const std::variant<int, std::string, std::vector<int>>& res);
std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
		case 0:
			result = 5;
			break;
		case 1:
			result = "string";
			break;
		case 2:
			result = std::vector<int>{ 1, 2, 3, 4, 5 };
			break;
		default:
			break;
	}
	return result;
}

int main(int argc, char *argv[]) {
    printRes(get_variant());
}

void printRes(const std::variant<int, std::string, std::vector<int>>& res) {
    if (std::holds_alternative<int> (res)){
        int a = std::get<int>(res);
        std::cout << a * 2 << std::endl;
    } else if(std::holds_alternative<std::string>(res) ) {
        std::string a = std::get<std::string>(res);
        std::cout << a << std::endl;
    }else if(std::holds_alternative<std::vector<int>>(res)){
        const auto& vec = std::get<std::vector<int>>(res);
        for (int o: vec ) {
            std::cout << o << " ";
        }
    };
}

//Задача 2. std::variant
//
//Описание
//
//(std::variant) удобно применять при разработке парсеров. Например, нет никакой универсальной функции, которая может возвращать значения разных типов в зависимости от контекста. В этом задании вам нужно использовать простую функцию, которая может возвращать число, код или массив чисел.
//
//std::variant<int, std::string, std::vector<int>> get_variant() {
//	std::srand(std::time(nullptr));
//	int random_variable = std::rand() % 3;
//	
//	std::variant<int, std::string, std::vector<int>> result;
//	switch (random_variable)
//	{
//		case 0:
//			result = 5;
//			break;
//		case 1:
//			result = "string";
//			break;
//		case 2:
//			result = std::vector<int>{ 1, 2, 3, 4, 5 };
//			break;
//		default:
//			break;
//	}
//	return result;
//}
//Вам необходимо обработать результат этой функции следующим образом: Если в результате функция получила int, то выводится число, умноженное на 2. Если в результате функция выводит строку, то просто выведите ее в консоль. Если в результате функция содержит векторные числа, нужно вывести все его элементы в консоль.