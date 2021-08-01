//problem: {1,2,4,2,2,1,1} result: 4

#include <iostream>
using namespace std;

//Get Bit
int getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}

//Set bit
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int unique3(int arr[], int n)
{
    int result = 0;
    //Loop for 64 bits
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        //Loop for all elements in array
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }

        //Set Bit if condition is true
        if (sum % 3 != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 6, 3, 2, 1, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << unique3(arr, n) << endl;
    return 0;
}