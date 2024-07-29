#include <iostream>
#include<thread>
#include <chrono>

//Очередь клиентов
//
//Вам нужно создать приложение, которое имитирует очередь в окошко.
// Для этого нужно создать два потока, работающие с одной разделяемой переменной.
//
//Первый поток имитирует клиента: раз в секунду он обращается к счётчику клиентов и увеличивает его на 1.
// Максимальное количество клиентов должно быть параметризировано.
//
//Второй поток имитирует операциониста: раз в 2 секунды он обращается к счётчику клиентов
// и уменьшает его на 1. «Операционист» работает до последнего клиента.

void client(int& count,int maxClients);
void operationist(int& count);

int main() {
    int count{1};
    int maxClients{10};
    std::thread t1(client, std::ref(count),maxClients);
    std::thread t2(operationist, std::ref(count));
    t1.join();
    t2.join();
    return EXIT_SUCCESS;
}


 void client(int& count,int maxClients)
{
    for(auto num{0}; num < maxClients; num++){
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
        count++;
        std::cout<< "Подошел еще один человек, всего: " << count << " человек\n";
    }
}
void operationist(int& count)
{
    while (count > 0){
        std::this_thread::sleep_for(std::chrono::nanoseconds(2000000000));
        count--;
        std::cout<< "Обслужен еще один человек, осталось: " << count << " человек\n";
    }
}
