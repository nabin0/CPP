#include <iostream>
#include <climits>
using namespace std;

int minJumps(int *arr, int n)
{
    int jumps[n];
    if (n == 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    for (int i = 0; i < n; i++)
    {
        jumps[i] = INT_MAX;
    }

    jumps[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]))
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[n - 1];
}

int main()
{
    int arr[] = {1, 3, 5, 5, 8, 4, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minJumps(arr, n);
    return 0;
}