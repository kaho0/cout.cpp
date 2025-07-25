#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void miracleSort(std::vector<int>& arr) {
    std::srand(std::time(0));
    while (!isSorted(arr)) {
        std::random_shuffle(arr.begin(), arr.end());
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 6, 2, 7, 4, 1};
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    miracleSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}