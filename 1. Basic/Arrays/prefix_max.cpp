// Problem: Print max till i while size of arr = n

#include <iostream>
#include <climits>
using namespace std;

int main()
{

    // User input
    int n;
    cin >> n;

    // Array element input
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx << endl;
    }

    return 0;
}