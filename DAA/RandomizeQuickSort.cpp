#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomPartition(int d[], int s, int e) {
    int randomIndex = s + (rand() % (e - s + 1));
    swap(d[randomIndex], d[e]); // Move random pivot to end

    int pivot = d[e];
    int pI = s; // Partition index

    for (int i = s; i < e; i++) {
        if (d[i] < pivot) {
            swap(d[i], d[pI]);
            pI++;
        }
    }
    swap(d[pI], d[e]); // Move pivot to its correct position
    return pI;
}

void quickSort(int d[], int s, int e) {
    if (s < e) {
        int pI = RandomPartition(d, s, e);
        quickSort(d, s, pI - 1);
        quickSort(d, pI + 1, e);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int arr[] = {23, 1, 10, 5, 2, 42, 2, 43, 23423};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:" << endl;
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "After Sorting:" << endl;
    printArray(arr, size);

    return 0;
}
