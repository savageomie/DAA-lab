#include <iostream>

int LinearSearch(int array[], int size, int key) {
    for (int index = 0; index < size; ++index) {
        if (array[index] == key) {
            return index; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int ArraySize;
    std::cout << "Enter the size of the array: ";
    std::cin >> ArraySize;

    if (ArraySize <= 0) {
        std::cout << "Invalid array size!" << std::endl;
        return 1; // Exit the program with an error code
    }

    int array[ArraySize];
    std::cout << "Enter " << ArraySize << " elements of the array:" << std::endl;
    for (int i = 0; i < ArraySize; ++i) {
        std::cin >> array[i];
    }

    int key;
    std::cout << "Enter the element to search for: ";
    std::cin >> key;

    int result = LinearSearch(array, ArraySize, key);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
