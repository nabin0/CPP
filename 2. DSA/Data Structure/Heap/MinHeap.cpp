#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void min_heapify(int arr[], int i, int n)
{
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int smallest = i;

    if (left <= n && arr[left] < arr[i])
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }

    if (right <= n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        // swap(arr,i, smallest);
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(arr, smallest, n);
    }
}

void build_minHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        min_heapify(arr, i, n);
    }
}

int main()
{
    //Sample arrays
    // int arr[] = {4, 5, 1, 6, 7, 3, 2}; //Correct Answer: 1 5 2 6 7 3 4
    int arr[] = {3, 4, 2, 5, 6, 1, 9}; //Correct answer: 1 4 2 5 6 3 9
    int n = sizeof(arr) / sizeof(arr[0]);

    //Invoking build heap
    build_minHeap(arr, n);

    //Printing array after Heapify
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}