#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {7, 10, 12, 12, 45, 45, 56, 65, 74, 78};
    int key, result, size;
    size = sizeof(arr) / sizeof(arr[0]);
    cout << "Searching an element in an array using binary search" << endl;
    cout << "Search Elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl
         << "Enter key: ";
    cin >> key;
    result = binarySearch(arr, size, key);
    if (result != -1)
    {
        cout << "Search successful at index: " << result;
    }
    else
    {
        cout << "Search Unsuccessful.";
    }
    return 0;
}