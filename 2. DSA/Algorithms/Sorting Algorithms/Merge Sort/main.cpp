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

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k, A[100];
    i = low;
    j = mid + 1;
    k = 0;

    //Merge two arrays
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            A[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            A[k] = arr[i];
            i++;
            k++;
        }
    }

    //Left elements of left array
    while (i <= mid)
    {
        A[k] = arr[i];
        i++;
        k++;
    }

    //Left elements of right array
    while (j <= high)
    {
        A[k] = arr[j];
        k++;
        j++;
    }

    //Putting sorted value back in main array
    for (int i = low; i <= high; i++)
    {
        arr[i] = A[i - low];
    }
}

void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {3, 7, 3, 5, 7, 9, 81, 24};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}