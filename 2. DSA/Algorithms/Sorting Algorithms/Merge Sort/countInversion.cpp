#include <iostream>
using namespace std;

long long merge(int *arr, int s, int mid, int e)
{
    long long countInv = 0;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int A[n1];
    int B[n2];

    for (int i = 0; i < n1; i++)
    {
        A[i] = arr[s + i];
    }
    for (int i = 0; i < n2; i++)
    {
        B[i] = arr[mid + i + 1];
    }

    //Merging
    int i = 0;
    int j = 0;
    int k = s;
    while (i < n1 && j < n2)
    {
        if (A[i] < B[j])
        {
            arr[k] = A[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = B[j];
            countInv += n1 - i;
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = A[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = A[j];
        j++;
        k++;
    }
    return countInv;
}

long long mergeSort(int *arr, int s, int e)
{
    long long countInv = 0;
    if (s < e)
    {
        int mid = (s + e) / 2;
        countInv += mergeSort(arr, s, mid);
        countInv += mergeSort(arr, mid + 1, e);
        countInv += merge(arr, s, mid, e);
    }
    return countInv;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long res = mergeSort(arr, 0, 5);
    cout << res << endl;

    return 0;
}