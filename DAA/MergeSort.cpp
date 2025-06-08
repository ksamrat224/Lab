#include <iostream>
using namespace std;
void Merge(int B[], int l, int m, int h)
{
    int size = h - l + 1;
    int lIndex = l;     
    int rIndex = m + 1; 
    int tempArr[size];  
    int tempIndex = 0;
    while (lIndex <= m && rIndex <= h)
    {
        if (B[lIndex] < B[rIndex])
        {
            tempArr[tempIndex] = B[lIndex];
            tempIndex++;
            lIndex++;
        }
        else
        {
            tempArr[tempIndex] = B[rIndex];
            tempIndex++;
            rIndex++;
        }
    }
    while (lIndex <= m)
    {
        tempArr[tempIndex++] = B[lIndex++];
    }
    while (rIndex <= h)
    {
        tempArr[tempIndex++] = B[rIndex++];
    }
    for (int i = l, tempIndex = 0; i <= h; i++, tempIndex++)
    {
        B[i] = tempArr[tempIndex];
    }
}
void mergeSort(int B[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(B, low, mid);      
        mergeSort(B, mid + 1, high); 
        Merge(B, low, mid, high);
    }
}

int main()
{
    int i, n;
    int arr[] = {23, 1, 10, 5, 2, 42, 2, 43, 23423};
    n = sizeof(arr) / sizeof(arr[0]);
    cout << endl
         << "Elements before sorting:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    mergeSort(arr, 0, n - 1);
    cout << endl
         << "Elements after sorting:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}