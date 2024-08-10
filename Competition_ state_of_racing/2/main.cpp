#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <random>
#include <mutex>
#include <atomic>

// Мьютекс для синхронизации вывода
std::mutex mtx;

void moveTo(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void clearLine(int len) {
    std::cout << "\033[1;2H";

    // Очистка от текущей позиции до конца строки
    std::cout << "\033[K";
}

int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Прогресс-бар
void progress_bar(int len, int thread_num, std::vector<std::thread>& thr) {
    const int startX = 1;
    const int startY = 10;
    std::string progress(len, ' ');
    int one_step_time = generateRandomNumber(100, 500);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < len; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(one_step_time));

        // Случайная вероятность ошибки
        bool isError = generateRandomNumber(1, 10) == 1;
        if (isError) {
            progress[i] = 'X';
        } else {
            progress[i] = '#';
        }

        {
            std::lock_guard<std::mutex> lock(mtx);
            moveTo(startX, startY + thread_num);
            std::cout << "\r\033[K";
            std::cout << thread_num + 1 << " " << thr[thread_num].get_id() << ": [" << progress << "]";
            std::cout.flush();
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;


    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << " завершён за " << duration.count() << " секунд\n";
        std::cout.flush();
    }
}

void progress_thread(int len, int numThreads) {
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(progress_bar, len, i, std::ref(threads));
    }

    for (auto& t : threads) {
        t.join();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int progress_barr_len = 20;
    int numThreads = 4;

    std::cout << "\tid\t\tprogress bar\ttime\n";
    progress_thread(progress_barr_len, numThreads);

    return 0;
}