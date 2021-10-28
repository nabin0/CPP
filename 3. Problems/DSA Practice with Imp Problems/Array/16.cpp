#include <iostream>
using namespace std;

int countInversion(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    // int arr[] = {2, 5, 4, 9, 7, 6, 1};
    int arr[] = {2,3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countInversion(arr, n);

    return 0;
}