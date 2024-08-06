#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

class Data {
public:
    int value;
    std::mutex mtx;

    Data(int v) : value(v) {}

};

static void swap_lock(Data& a, Data& b) {
    a.mtx.lock();
    b.mtx.lock();

    std::swap(a.value, b.value);
    a.mtx.unlock();
    b.mtx.unlock();
}

static void swap_scoped_lock(Data& a, Data& b) {
    std::scoped_lock<std::mutex, std::mutex> lock(a.mtx, b.mtx);

    std::swap(a.value, b.value);
}

static void swap_unique_lock(Data& a, Data& b) {
    std::unique_lock<std::mutex> lockA(a.mtx);
    std::unique_lock<std::mutex> lockB(b.mtx);

    std::swap(a.value, b.value);
}
int main() {
    Data data1(1);
    Data data2(2);

    std::cout << "Before swap: data1.value = " << data1.value << ", data2.value = " << data2.value << "\n";

     swap_lock(data1, data2);
     //swap_scoped_lock(data1, data2);
     //swap_unique_lock(data1, data2);

    std::cout << "After swap: data1.value = " << data1.value << ", data2.value = " << data2.value << "\n";

    return 0;
}
