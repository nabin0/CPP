//returns true if the sum of pair (2 elements is == k)
#include <iostream>
using namespace std;

//Function with O(n^2) solution
bool pairsum1(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << "Indices: " << i << ", " << j << endl;
                return true;
            }
        }
    }
    return false;
}

// Function 2 with O(n) solution
bool pairsum2(int arr[], int n, int k)
{
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (arr[i] + arr[j] == k)
        {
            cout << "Indices: " << i << ", " << j << endl;
            return true;
            break;
        }
        else if (arr[i] + arr[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

int main()
{
    int n = 8;
    int arr[n] = {1, 3, 5, 7, 8, 9, 12, 15};
    int k = 17;
    cout << "Function 1 ---> " << endl;
    cout << pairsum1(arr, n, k) << endl;
    cout << "\nFunction 2 ---> " << endl;
    cout << pairsum2(arr, n, k) << endl;
    return 0;
}