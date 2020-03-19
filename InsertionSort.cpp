#include <iostream>
#include <random>

template<typename T>
void InsertionSort(int len, T arr) {
    for(int i = 1; i < len; i++)
        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--)
            std::swap(arr[j-1], arr[j]);
}

int main() {
    std::random_device gen;
    std::uniform_real_distribution<> uid(1, 40);
    int size = uid(gen);
    int arr[size];
    for(int i = 0; i != size; ++i)
        arr[i] = uid(gen);

    for(auto &b: arr)
        std::cout << b << " ";
    std::cout << '\n';

    CountingSort(size, arr);

    for(auto &b: arr)
        std::cout << b << " ";
}
