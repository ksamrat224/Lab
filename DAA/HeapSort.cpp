#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int l, r, largest;
    largest = i; // index of largest element
    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    cout << endl << "Array Satisfying a Max Heap:\n";
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);  // Reduce heap size by 1 and heapify root
    }
}

int main() {
    int arr[] = {12, 8, 9, 6, 4, 10, 7, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array:\n";
    printArray(arr, n);
    
    heapSort(arr, n);
    
    cout << endl << "After Sorting:\n";
    printArray(arr, n);
    
    return 0;
}
