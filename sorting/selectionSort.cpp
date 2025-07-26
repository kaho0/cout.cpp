#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    cout << "Selection Sort\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int& x : arr) cin >> x;

    selectionSort(arr);

    cout << "Sorted array: ";
    for(int x : arr) cout << x << " ";
    return 0;
}
