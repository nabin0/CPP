#include <iostream>
#include <climits>
using namespace std;

int kadanes(int arr[], int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
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

    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadanes(arr, n);
    int totalSum = 0;

    //Total sum and reversing sign of array elements
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalSum + kadanes(arr, n);

    int maxSum = max(wrapsum, nonwrapsum);
    cout << maxSum << endl;

    return 0;
}