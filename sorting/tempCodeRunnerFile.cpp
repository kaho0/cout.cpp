#include <iostream>
#include <vector>
using namespace std;

int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i+1], arr[high]);
    return i+1;
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
