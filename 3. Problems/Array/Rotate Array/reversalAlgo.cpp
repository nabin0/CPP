#include <iostream>
using namespace std;

//Reverse array
void reverse(int arr[], int startPtr, int endPtr)
{
    while (startPtr < endPtr)
    {
        int temp = arr[startPtr];
        arr[startPtr] = arr[endPtr];
        arr[endPtr] = temp;
        startPtr++;
        endPtr--;
    }
}

//Rotate left
void rotate(int arr[], int n, int d)
{
    if (d == 0)
    {
        return;
    }

    d = d % n;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
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