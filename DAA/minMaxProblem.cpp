#include <iostream>
using namespace std;
struct MM
{
    int min, max;
};
MM findMinMax(int arr[], int low, int high)
{
    if (low == high || high == low + 1)
    {
        MM value;
        value.min = min(arr[low], arr[high]);
        value.max = max(arr[low], arr[high]);
        return value;
    }
    else
    {
        int mid = (low + high) / 2;
        MM leftValue = findMinMax(arr, low, mid);
        MM rightValue = findMinMax(arr, mid + 1, high);
        MM value;
        value.min = min(leftValue.min, rightValue.min);
        value.max = max(leftValue.max, rightValue.max);
        return value;
    }
}
int main()
{
    MM min_max;
    int arr[] = {23, 1, 0, 10, 5, 2, 42, 2, 43, 44};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    min_max = findMinMax(arr, 0, size - 1);
    cout << endl
         << "Min: " << min_max.min << endl;
    cout << "Max: " << min_max.max << endl;
    return 0;
}