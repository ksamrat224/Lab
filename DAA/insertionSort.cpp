#include <iostream>
using namespace std;
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int k = i - 1;
        int temp = arr[i];
        while (k >= 0 && arr[k] > temp)
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = temp;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {23, 1, 10, 5, 2, 42, 2, 43, 44};
    cout << "Unsorted array: " << endl;
    printArray(arr, 9);
    insertionSort(arr, 9);
    cout << endl
         << "Sorted array: " << endl;
    printArray(arr, 9);
}