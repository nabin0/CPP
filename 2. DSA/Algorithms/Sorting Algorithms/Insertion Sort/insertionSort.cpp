#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionsort(int arr[], int n)
{
    int i = 0;
    int j = 1;

    while (j <= n)
    {
        if (arr[i] > arr[j])
        {
            for (int k = i; k > 0; k--)
            {
                if (arr[k] > arr[j])
                {
                    swap(arr, k, j);
                }else{
                    break;
                }
            }
            i++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
}

int main()
{
    int arr[] = {3, 5, 2, 6, 9, 1};
    insertionsort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}