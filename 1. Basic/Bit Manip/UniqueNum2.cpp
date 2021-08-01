// Find 2 uniue nums e.g {1,2,3,4,3,2,1,5} reuslt will be {4,5}
#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void uniqueNum(int arr[], int n)
{
    //Find xor sum of all elements(numbers)
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int temp = xorsum;

    //Find Position of setBit (1) in xorsum
    int pos = 0;
    int setbit = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    //Find xorsum of elements that have setbit at position (pos) i.e 1 at position (pos)
    int newSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos - 1))
        {
            newSum = (newSum ^ arr[i]);
        }
    }

    cout << newSum << endl;

    //Apply xor operation with total xorsum  to get another number
    cout << (newSum ^ temp) << endl;
}

int main()
{
    int arr[] = {1, 3, 5, 3, 1, 6, 7, 7};
    int n = 8;
    uniqueNum(arr, n);
    return 0;
}