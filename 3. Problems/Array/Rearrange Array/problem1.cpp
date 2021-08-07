//Problem : Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array. If the element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

#include <iostream>
using namespace std;

void rearrange(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i] != i)
        {
            arr[i] = -1;
        }
    }
}

int main()
{
    int arr[10] = {2, 5, 4, 7, 8, -1, 9, -1, -1, -1};
    int n = 10;
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
