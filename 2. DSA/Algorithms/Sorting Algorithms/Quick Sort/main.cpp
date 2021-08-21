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

//Partitioning arr from low to high
int partition(int *arr, int low, int high)
{
    int pivot = arr[low]; // first array element as a Pivot element
    int p = low + 1;
    int q = high;
    do
    {
        while (pivot >= arr[p]) //move p to next (increament if the element at p is lesser or equals to pivot)
        {
            p++;
        }
        while (pivot < arr[q]) // move q to element before(decrement) till small element than pivot is found
        {
            q--;
        }
        if (p < q) // Swap elements at this condition when p and q are in required psition
        {
            swap(&arr[p], &arr[q]);
        }
    } while (p < q);
    //Swap elem at q with array[low] when p > q
    swap(&arr[low], &arr[q]);

    return q;
}

void quickSort(int *arr, int low, int high)
{
    int partitionPivotIdx;

    if (low < high)
    {
        partitionPivotIdx = partition(arr, low, high);
        quickSort(arr, low, partitionPivotIdx - 1);  //Quick sort on left sub array
        quickSort(arr, partitionPivotIdx + 1, high); //Quick sort on right sub array
    }
}

int main()
{
    int arr[] = {4, 1, 6, 8, 2, 9};
    int s = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, s);
    quickSort(arr, 0, s - 1);
    printArr(arr, s);

    return 0;
}