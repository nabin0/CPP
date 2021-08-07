#include <iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

int main()
{
    int arr[] = {3, 5, 6, 6, 7, 8, 9};
    int n = 7;

    reverse(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}