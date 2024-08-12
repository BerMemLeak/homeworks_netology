#include <iostream>
#include <vector>
#include <thread>
#include <iterator>

template <class InputIterator, class Function>
void parallel_for_each(InputIterator start, InputIterator end, Function func) {
    auto length = std::distance(start, end);

    if (length <= 1) {
        if (start != end) {
            func(*start);
        }
        return;
    }

    InputIterator mid = std::next(start, length / 2);

    std::thread first_half(parallel_for_each<InputIterator, Function>, start, mid, func);
    parallel_for_each(mid, end, func);

    first_half.join();
}

int main() {
    std::vector<double> arr = {64, 25, 12, 22, 11};

    std::cout << "первоначальный массив: ";
    for (double num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto print_and_square = [](double& x) {
        x = x * x;
    };

    // Параллельный вызов for_each
    parallel_for_each(arr.begin(), arr.end(), print_and_square);

    std::cout << "измененный массив: ";

    for (double num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
