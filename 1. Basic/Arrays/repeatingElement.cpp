// Problem: Find the first repeating element. i.e repeating element whose index is lowest.
#include <iostream>
#include <climits>
using namespace std;

void repeatMin(int arr[], int n)
{
    int N = 1000;
    int idx[N];

    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }
    if (minidx == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << "Index is : " << minidx << endl;
    }
}


int repeating_element(int *A, int n){ // Frst repeating element
    const int N = 1e5;
    int arr[N] ;
        for (int i = 0; i < N; i++)
    {
        arr[i] = -1;
    }

    for(int i = 0 ;i < n; i++){
        if(arr[A[i]] != -1){
            return arr[A[i]];
        }
        arr[A[i]] = i;
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    repeatMin(arr, n);
    cout << repeating_element(arr, n);
    return 0;
}