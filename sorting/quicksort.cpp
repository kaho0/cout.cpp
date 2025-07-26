#include <iostream>
#include <vector>
using namespace std;

int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[low]; // First element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // Find element greater than pivot
        while (i <= high && arr[i] <= pivot) i++;

        // Find element smaller than pivot
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // Put pivot in correct place
    return j;
}


void quickSort(vector<string>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n;
    cout << "Quick Sort\nEnter number of elements: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter elements: ";
    for(string& x : arr) cin >> x;

    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for(const string& x : arr) cout << x << " ";
    return 0;
}
