/*
1
11
202
3003
40004
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows" << endl;
    cin >> n;

    // Logic
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x > 1)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j == 1 || j == i)
                {
                    cout << i - 1;
                }
                else
                {
                    cout << "0";
                }
            }
        }
        else
        {
            for (int s = 1; s <= i; s++)
            {
                cout << "1";
            }
        }
        cout << endl;
        x++;
    }

    return 0;
}