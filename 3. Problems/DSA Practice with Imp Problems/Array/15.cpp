#include <iostream>
using namespace std;

void reverseArray(int *arr, int start, int end)  // reversre the array from start index to end index
{
    if(start == end){
        return;
    }
    int temp;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;end--;
    }
}

void nextPermutation(int *arr, int n)
{
    int idx = -1; 

    for (int i = n - 1; i >= 0; i--) // loop from right to find index of elem whicch is not following ascending order from back & break when find it
    {
        if (arr[i] > arr[i - 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1) // condition if there is no next permutation of given array retrned reversed array
    {
        reverseArray(arr, 0, n - 1);
    }
    else
    {
        int prev = idx;

        for (int i = n-1; i > prev; i--) // Find nearest greater in the array after the idx and swap with idx value
        {
            if (arr[i] > arr[idx - 1])
            {
                prev = i;
                break;
            }
        }

        swap(arr[prev], arr[idx - 1]);

        reverseArray(arr, idx, n - 1); // reversing array after the idx to get next permutation 
    } 
}

int main()
{
    int arr[] = {0,1,2,5,3,3,0};
    // int arr[] = {7,1,3,2,1}; // ans: 7 2 1 1 3
    // int arr[] = {1,2,3};
    // int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextPermutation(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}