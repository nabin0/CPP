#include <iostream>
using namespace std;

void print_array(int arr[], int size)
{
    for (int i; i < size; i++)
    {
        cout << i << " ";
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);

    return 0;
}