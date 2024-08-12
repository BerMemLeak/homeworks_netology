//
// Created by user on 10.08.2024.
//

//Сортировка выбором
//
//Реализуйте алгоритм сортировки выбором.
//Сортировка выбором состоит в том, что в неупорядоченном списке находится наименьший элемент.
//Выбранный в исходном списке минимальный элемент записывается
//на i-е место исходного списка (i=1,2,…,п), а элемент с i-го места — на место выбранного.
//При этом очевидно, что уже упорядоченные элементы, а они будут расположены, начиная с первого места,
//исключаются из дальнейшей сортировки, поэтому длина списка, участвующего в каждом последующем просмотре,
//должна быть на один элемент меньше предыдущего.
//Поиск минимального элемента реализуйте в виде асинхронной задачи.
//Результат должен возвращаться в основной поток через связку std::promise-std::future.

#include <vector>
#include <iostream>
#include <thread>
#include <future>

int find_min(const std::vector<double> vec, int start, int end){
    int min_index{start};
    for(int i{start + 1}; i < end; ++i){
        if(vec[i] < vec[min_index]){
            min_index = i;
        }
    }
    return min_index;
}

void sort(std::vector<double >& arr){
    int arr_size = arr.size();
    for (int i{0}; i < arr_size ; ++i) {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread find_min_thread([&arr, &promise, i,arr_size]() {
            int min_index = find_min(arr , i, arr_size);
            promise.set_value(min_index);
        });
        int min_index = future.get();
        if (min_index != i){
            std::swap(arr[i], arr[min_index]);
        }
        find_min_thread.detach();
    }


}
int main(){
    std::vector<double> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}