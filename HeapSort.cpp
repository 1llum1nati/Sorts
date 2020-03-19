#include <iostream>
#include <random>

template<typename T>
void heapify(T arr, int len, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && arr[left] > arr[largest])
		largest = left;

	if (right < len && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, len, largest);
	}
	
}

template<typename T>
void HeapSort(int len, T arr) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(arr, len, i);
	}

	for (int i = len - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	std::random_device gen;
    std::uniform_real_distribution<> uid(5, 10);
    int size = uid(gen);
    float arr[size];
    for(int i = 0; i != size; ++i)
        arr[i] = uid(gen);

    for(auto &b: arr)
        std::cout << b << " ";
    std::cout << '\n';

    HeapSort(size, arr);
    
    for(auto &b: arr)
        std::cout << b << " ";
}
