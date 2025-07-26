#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> a, b;

    // Split array into two halves
    for (int i = left; i <= mid; i++) a.push_back(arr[i]);
    for (int i = mid + 1; i <= right; i++) b.push_back(arr[i]);

    int i = 0, j = 0, k = left;

    // Merge both halves
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // Copy any remaining elements
    while (i < a.size()) arr[k++] = a[i++];
    while (j < b.size()) arr[k++] = b[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
 