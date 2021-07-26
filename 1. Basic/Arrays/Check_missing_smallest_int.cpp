// Find the smallest missing integer form a array

#include <iostream>
using namespace std;

void smallestMissingInt(int arr[], int n)
{
    const int N = 1e4 + 2;
    int check[N];

    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            check[arr[i]] = true;
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (check[i] == false)
        {
            cout << i << " is the smallest missing integer." << endl;
            break;
        }
    }
}

int main()
{
    cout << "Enter the size of array\n";
    int n;
    cin >> n;

    cout << "Enter the elements of the array.\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    smallestMissingInt(arr, n);

    return 0;
}