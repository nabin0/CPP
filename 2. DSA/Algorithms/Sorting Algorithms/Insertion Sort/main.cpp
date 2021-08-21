#include <iostream>
using namespace std;

void printArr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n)
{
    int key, j, temp;
    for (int i = 1; i <= n - 1; i++) //For no of passes
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {12, 34, 5, 6, 6, 7, 47, 32, 8784, 8486834, 34747};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArr(arr, n);
    return 0;
}