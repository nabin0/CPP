/*
Problem: Print this pattern
1
01
101
0101
10101
010101
1010101

*/

#include <iostream>
using namespace std;

int main()
{
    // Taking row size as user input
    int n;
    cin >> n;

    // algo for printing pattern
    for (int i = 1; i <= n; i++)
    {
        // using condition for first value to be 1 or 0
        int value = i % 2 != 0 ? true : false;

        // Printing items
        for (int itm = 0; itm < i; itm++)
        {
            cout << value << " ";
            // alternating values between 0 and 1
            value = 1 - value;
        }
        cout << endl;
    }

    return 0;
}