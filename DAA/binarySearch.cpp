#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int start, int end)
{
    if (start <= end)
    {

        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {

            return mid;
        }
        else if (key < arr[mid])
        {
            return binarySearch(arr, key, start, mid - 1);
        }
        else
        {
            return binarySearch(arr, key, mid + 1, end);
        }
    }
    return -1;
}

int main()
{
    int arr[100], size, key, result;
    cout << "Enter number of elements in array: ";
    cin >> size;
    cout << "Enter the elements in sorted:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key: ";
    cin >> key;
    result = binarySearch(arr, key, 0, size - 1);
    if (result == -1)
    {
        cout << "Search Unsuccessful!!";
    }
    else
    {
        cout << "Search Successful at index: " << result;
    }
    return 0;
}