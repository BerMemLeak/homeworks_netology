#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
//Параллельные вычисления
//
//Напишите программу для расчёта суммы двух векторов.
//Распараллельте эту программу на 2, 4, 8 и 16 потоков.
//Определите, какое количество потоков даёт самый быстрый результат.
//Сравните результаты выполнения для массивов из 1 000, 10 000, 100 000 и 1 000 000 элементов.
//Время выполнения для каждого варианта сведите в таблицу и выведите её в консоль.
//Первый запущенный поток должен вывести на экран доступное количество аппаратных ядер.

void sumVectorsPart(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& result, int start, int end) {
    for (int i = start; i < end; ++i) {
        result[i] = a[i] + b[i];
    }
}


void parallelSumVectors(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& result, int numThreads) {
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
    int threadCounts = static_cast<int>(std::thread::hardware_concurrency());

    std::cout << "Количество аппаратных ядер: " << threadCounts << "\n\n";

    std::cout  << "\t\t\t\t1000\t\t10000\t100000\t1000000\n";

    for (auto thr = 1; thr <= threadCounts; thr*=2) {

        std::cout << thr <<" потоков "<< "\t";
        for (auto& size: sizes) {
            std::vector<double> a(size, 1);
            std::vector<double> b(size, 2);
            std::vector<double> result(size);

            auto start = std::chrono::high_resolution_clock::now();

            parallelSumVectors(a, b, result, thr);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            std::cout << std::setw(10) << duration.count();        }
        std::cout <<"\n";
    }

    return 0;
}
