#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

//Параллельные вычисления
//
//Напишите программу для расчёта суммы двух векторов.
//Распараллельте эту программу на 2, 4, 8 и 16 потоков.
//Определите, какое количество потоков даёт самый быстрый результат.
//Сравните результаты выполнения для массивов из 1 000, 10 000, 100 000 и 1 000 000 элементов.
//Время выполнения для каждого варианта сведите в таблицу и выведите её в консоль.
//Первый запущенный поток должен вывести на экран доступное количество аппаратных ядер.

void sumVectorsPart(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int start, int end) {
    for (int i = start; i < end; ++i) {
        result[i] = a[i] + b[i];
    }
}


void parallelSumVectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int numThreads) {
    std::vector<std::thread> threads;
    int n = a.size();
    int partSize = n / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int start = i * partSize;
        int end = (i == numThreads - 1) ? n : start + partSize;
        threads.emplace_back(sumVectorsPart, std::cref(a), std::cref(b), std::ref(result), start, end);
    }

    for (auto& t : threads) {
        t.join();
    }
}

int main() {
    std::vector<int> sizes = {1000, 10000, 100000, 1000000};
    std::vector<int> threadCounts = {1,2, 4, 8, 16};

    unsigned int numCores = std::thread::hardware_concurrency();
    std::cout << "Количество аппаратных ядер: " << numCores << "\n\n";

    std::cout << "Размер массива | Потоки | Время выполнения (мс)\n";
    std::cout << "---------------------------------------------\n";

    for (int size : sizes) {
        std::vector<int> a(size, 1);
        std::vector<int> b(size, 2);
        std::vector<int> result(size);

        for (int numThreads : threadCounts) {
            auto start = std::chrono::high_resolution_clock::now();

            parallelSumVectors(a, b, result, numThreads);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            std::cout << size << "          | " << numThreads << "      | " << duration.count() << "\n";
        }
        std::cout << "---------------------------------------------\n";
    }

    return 0;
}
