// Problem: Print all subarray of an array.
// Total sub array = (n*(n+1))/2

#include <iostream>
using namespace std;

void subArr(int arr[], int n)
{
    int totalSubArr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            totalSubArr++;
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    cout << "Total sub array are :" << totalSubArr << endl;
}

int main()
{
    cout<<"Enter the size of array: "<<endl;
    int n;
    cin >> n;

    cout<<"Enter the Elements of array: "<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    subArr(arr, n);
    return 0;
}