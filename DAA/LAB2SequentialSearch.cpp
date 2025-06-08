#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 123, 45, 78, 98, 124, 45, 78, 65};
    int key, result, size;
    size = sizeof(arr) / sizeof(arr[0]);
    cout << "Searching an element in an array using linear search" << endl;
    cout << "Search Elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl
         << "Enter key: ";
    cin >> key;
    result = sequentialSearch(arr, size, key);
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