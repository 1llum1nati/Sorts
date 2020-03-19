#include <iostream>
#include <random>

void CountingSort(int len, int *arr) {
    int *temp = new int[len];
    int min = arr[0], max = arr[0], newSize;
    for (int i = 1; i < len; ++i) { //max/min
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    newSize = max - min + 1;

    int *unique = new int[newSize]; 
    for (int i = min; i < len + min; ++i) { //подсчёт встречаемости каждого числа
        unique[arr[i-min]-min]++;  
    }

    for (int i = 0; i < newSize - 1; ++i) { //кумулятивное сложение
        unique[i+1] += unique[i];
    }

    for (int i = newSize; i > 0; --i) { //смещение вправо
        unique[i] = unique[i-1];
    }
    unique[0] = 0;

    for(int i = 0; i < len; ++i) { //новый отсортированный массив
        temp[unique[arr[i]-min]] = arr[i];
        unique[arr[i]-min]++;
    }

    for (int i = 0; i < len; ++i)
        arr[i] = temp[i];
}

int main() {
    std::random_device gen;
    std::uniform_real_distribution<> uid(1, 50);
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