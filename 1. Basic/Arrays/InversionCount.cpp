#include <iostream>
using namespace std;

long long countInversion(int *arr, int n)
{
    int countInv = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                countInv++;
            }
        }
    }
    return countInv;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long res = countInversion(arr, n);
    cout<<res<<endl;
    return 0;
}