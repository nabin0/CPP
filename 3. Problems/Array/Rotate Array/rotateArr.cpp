#include <iostream>
using namespace std;

void rotate(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
    {
        int temp = arr[n - 1];
        for (int i = n-1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}

int main()
{
    int arr[] = {1, 4, 6, 2, 4};
    rotate(arr, 5, 2);

    //Printing array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}