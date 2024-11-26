#include <iostream>

int BinarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == key) {
            return middle; // Key found at index middle
        } else if (arr[middle] < key) {
            left = middle + 1; // Search in the right half
        } else {
            right = middle - 1; // Search in the left half
        }
    }

    return -1; // Key not found
}

int main() {
    int ArraySize = 5;
    int Arr[ArraySize] = {3, 4, 9, 11, 13}; // Predefined sorted array
    int Key;

    std::cout << "Enter the element to search for: ";
    std::cin >> Key;

    int result = BinarySearch(Arr, ArraySize, Key);

    if (result == -1) {
        std::cout << "Element not found" << std::endl;
    } else {
        std::cout << "Element found at index " << result << std::endl;
    }

    return 0;
}
