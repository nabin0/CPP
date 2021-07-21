/*
name: mountain pattern

1           1
1 2       2 1  
1 2 3   3 2 1
1 2 3 4 3 2 1 
*/

#include <iostream>
using namespace std;

int main()
{

// Taking input
    int n;
    cin >> n;

// Logic for pattern
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= i; j++)
        {
            cout << j;
        }
        int spaces = 2 * n - 1 - 2 * i;
        for (int sp = 0; sp < spaces; sp++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            if (j == n)
            {
                continue;
            }

            cout << j;
        }

        cout << endl;
    }

    return 0;
}
