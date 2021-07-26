// Problem : find the longest arithmetic subarray. Arithmetic sub array is array having equal difference between its conjuctive elements

#include <iostream>
using namespace std;

void longArithmeticSarray(int arr[], int n)
{
    int prevDiff = arr[1] - arr[0];
    int currIdx = 1;
    int size = 2;
    int result = 0;

    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == prevDiff)
        {
            size++;
        }
        else
        {
            prevDiff = arr[i] - arr[i - 1];
            size = 2;
            currIdx = i;
        }
        result = max(result, size);
    }
    cout << result << endl;

    cout << "The array is : " << endl;

    for (int i = (currIdx - result); i < currIdx; i++)
    {
        cout << arr[i] << " ";
    }
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

    longArithmeticSarray(arr, n);

    return 0;
}