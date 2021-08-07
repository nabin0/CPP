#include <iostream>
using namespace std;

//First occurance of a key
int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}

//Last occurance
int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    int restArr = lastocc(arr, n, i + 1, key);
    if (restArr != -1)
    {
        return restArr;
    }
    if (arr[i] == key)
    {
        return i;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 4, 4, 5, 6, 74, 2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    cout << firstocc(arr, n, 0, key) << endl;
    cout << lastocc(arr, n, 0, key) << endl;

    return 0;
}