#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>



//Нужно модифицировать задание 1 к первому уроку так, чтобы счётчик клиентов был атомарным.
//Все операции со счётчиков должны быть атомарными.
//Проверьте работу различными способами упорядочения доступа к памяти.

void client(std::atomic<int>& count, int maxClients, std::atomic<bool>& finished);
void operationist(std::atomic<int>& count, std::atomic<bool>& finished);

int main() {
    std::atomic<int> count{0};
    int maxClients{10};
    std::atomic<bool> finished{false};

    std::thread t1(client, std::ref(count), maxClients, std::ref(finished));
    std::thread t2(operationist, std::ref(count), std::ref(finished));

    t1.join();
    t2.join();

    return EXIT_SUCCESS;
}

void client(std::atomic<int>& count, int maxClients, std::atomic<bool>& finished) {
    for (int num = 0; num < maxClients; num++) {
        finished.store(false, std::memory_order_relaxed);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int currentCount = count.fetch_add(1) + 1;
        std::cout << "Подошел еще один человек, всего: " << currentCount << " человек\n";
        finished.store(true, std::memory_order_relaxed);
    }
}

void operationist(std::atomic<int>& count, std::atomic<bool>& finished) {
    while (!finished.load(std::memory_order_relaxed) || count.load() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        int currentCount = count.load();
        if (currentCount > 0) {
            count.fetch_sub(1);
            std::cout << "Обслужен еще один человек, осталось: " << currentCount - 1 << " человек\n";
        }
    }
}
