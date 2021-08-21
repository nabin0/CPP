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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int minIdx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int main()
{
    int arr[] = {3, 7, 3, 5, 1, 78, 34, 344, 1, 4, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printArr(arr, size);

    return 0;
}