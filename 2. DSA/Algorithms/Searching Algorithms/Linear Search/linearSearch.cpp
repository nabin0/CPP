#include <iostream>
using namespace std;

// Linear search 
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter the size of array." << endl;
    int n;
    cin >> n;

    int arr[n];
    cout<<"Enter the elements of array."<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the element you want search."<<endl;

    int key;
    cin >> key;

    cout << "The entered element is found at index: " << linearSearch(arr, n, key);
    return 0;
}