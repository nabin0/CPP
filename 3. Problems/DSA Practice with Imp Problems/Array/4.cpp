#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int zeros = -1;
    int ones = -1, twos = -1;
    //counting valaues of numbers present in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
        }
        else if (arr[i] == 1)
        {
            ones++;
        }
        else if (arr[i] == 2)
        {
            twos++;
        }
    }
    //Putting values in the original in sorted order
    static int j = 0;
    for (int i = 0; i <= zeros; i++)
    {
        arr[j++] = 0;
    }
    for (int i = 0; i <= ones; i++)
    {
        arr[j++] = 1;
    }
    for (int i = 0; i <= twos; i++)
    {
        arr[j++] = 2;
    }
}


int main()
{
    int arr[] = {1, 0, 2, 1, 2, 2, 1, 0};
    sort(arr, 8);
    //Printing array
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}