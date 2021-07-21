/*
name: pattern triangle

      1 
    2 3 2
  3 4 5 4 3
4 5 6 7 6 5 4

*/

#include <iostream>
using namespace std;

int main()
{
    // user input
    int n;
    cin >> n;

    // Logic u=implementation
    for (int i = 1; i <= n; i++)
    {
        // Loop for spaces
        for (int j = 1; j <= 2 * n - i * 2; j++)
        {
            cout << " ";
        }

        // Loop for columns till icreasing values
        int elm = i;
        for (int k = 1; k <= i; k++)
        {
            cout << elm << " ";
            elm++;
        }

        // Loop after starting decreasing of value
        elm = elm - 2;
        for (int j = 1; j < i; j++)
        {
            cout << elm-- << " ";
        }

        cout << endl;
    }

    return 0;
}