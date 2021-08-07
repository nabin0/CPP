/*

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int arr[] = {4, 6, 2, 3, 9};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

*/

// -----------Above code Practice--------

#include <iostream>
using namespace std;


//Function to print array
void printArr(int arr[], int i, int j)
{
    for (int k = i; k < j; k++)
    {
        cout << arr[k] << " ";
    }
}

//Function to swap to values
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


//Function to divide array
int partition(int arr[], int startPtr, int endPtr)
{
    int pivot = arr[endPtr - 1];
    int i = startPtr - 1;

    for (int j = startPtr; j < endPtr - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, endPtr - 1);
    return i + 1;
}

//Quicksort Algorithm
void quickSort(int arr[], int startPtr, int endPtr)
{

    if (startPtr < endPtr)
    {
        int pivotIdx = partition(arr, startPtr, endPtr); //Function to divide array into small parts
        quickSort(arr, startPtr, pivotIdx);
        quickSort(arr, pivotIdx + 1, endPtr);
    }
}

int main()
{

    int arr[] = {2, 6, 4, 3, 8, 90, 7, 8};
    int s = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, 8);

    printArr(arr, 0, 8);

    return 0;
}