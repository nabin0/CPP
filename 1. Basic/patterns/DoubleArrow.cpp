/*
Name : Double arrow  pattern

            1 
        2 1   1 2 
    3 2 1       1 2 3 
4 3 2 1           1 2 3 4 
    3 2 1       1 2 3 
        2 1   1 2 
            1 

*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    n = 7;
    // cin>>n;

    // Pattern First loop for rows till ros/2
    int hnum = n / 2 + 1;
    for (int i = 1; i <= hnum; i++)
    {
        // loop for space in the begin
        for (int j = 1; j <= hnum * hnum - hnum * i; j++)
        {
            cout << " ";
        }
        // for value after first space
        int val = i;
        for (int j = 1; j <= i; j++)
        {
            cout << val-- << " ";
        }
        // for middle space
        for (int j = 0; j <= (hnum * (i - 1) - 3); j++)
        {
            cout << " ";
        }
        // for value after middle spaces
        if (i != 1)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    // Loop for rows after row/2
    for (int i = 1; i <= hnum - 1; i++)
    {

        for (int j = 1; j <= hnum * i; j++)
        {
            cout << " ";
        }

        int val = hnum - i;
        for (int j = 1; j <= hnum - i; j++)
        {
            cout << val-- << " ";
        }

        for (int j = 0; j <= hnum * 2 - hnum * i; j++)
        {
            cout << " ";
        }

        if (i != hnum - 1)
        {
            for (int j = 1; j <= hnum - i; j++)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}