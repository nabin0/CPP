#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a1[n1];
    int a2[n2];

    //Putting values of arr into a1 and a2
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[i + l];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = arr[mid + 1 + i];
    }

    //Putting back values of a1 and a2 into arr in sorting order
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a1[i] > a2[j])
        {
            arr[k] = a2[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = a1[i];
            k++;
            i++;
        }
    }

    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{

    int arr[] = {4, 6, 4, 45, 4, 4, 2, 24, 81, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n);
    cout << n << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}