//Problem statement: Find the unique nmber whic is not repwated twice {1,3,4,3,1} 4 is answer in this case
#include <iostream>
using namespace std;

int findunique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 4, 5, 1, 5, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findunique(arr, n) << endl;
    return 0;
}