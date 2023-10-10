#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = arr.size();
    cout<<"Before Sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<endl<<endl;
    quickSort(arr, 0, n - 1);
    cout<<"After sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
