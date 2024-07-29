#include <iostream>
#include<thread>
#include <chrono>


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
