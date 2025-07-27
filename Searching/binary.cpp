#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& bookIDs, int target) {
    int left = 0;
    int right = bookIDs.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (bookIDs[mid] == target) {
            return mid;  // Target found at index mid
        }
        else if (bookIDs[mid] < target) {
            left = mid + 1;  // Search right half
        }
        else {
            right = mid - 1; // Search left half
        }
    }
    return -1;  // Target not found
}

int main() {
    vector<int> bookIDs = {101, 203, 305, 407, 509, 610, 712};  // Sorted list of book IDs
    int target;

    cout << "Enter book ID to search: ";
    cin >> target;

    int result = binarySearch(bookIDs, target);

    if (result != -1)
        cout << "Book ID " << target << " found at index " << result << ".\n";
    else
        cout << "Book ID " << target << " not found in the database.\n";

    return 0;
}
