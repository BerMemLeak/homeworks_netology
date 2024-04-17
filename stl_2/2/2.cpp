#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>


template <class T,class U>
	void print_container(T& kontainer){
	std::for_each(kontainer.begin(), kontainer.end(), [](const U& n) { 
		std::cout << n << ' '; 
	});
	std::cout << std::endl;
		
};


int main(int argc, char *argv[]) {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container<std::set<std::string>, std::string>(test_set); // four one three two
	
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container<std::list<std::string>, std::string>(test_list); // one two three four
	
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container<std::vector<std::string>, std::string>(test_vector); // one two three four

}


//Задача 2. Печать контейнера
//
//Описание
//
//Нужно реализовать шаблонную функцию, которая печатает содержимое контейнера.
//
//Контейнер может быть любым:
//
//std::set
//std::vector
//std::list
//Пример правильной работы программы
//
//std::set<std::string> test_set = { "one", "two", "three", "four" };
//print_container(...); // four one three two. помните почему такой порядок? :)

//std::list<std::string> test_list = { "one", "two", "three", "four" };
//print_container(...); // one, two, three, four
//
//std::vector<std::string> test_vector = { "one", "two", "three", "four" };
//print_container(...); // one, two, three, four