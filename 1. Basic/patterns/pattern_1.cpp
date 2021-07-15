/*
1  
11  
111   
1001   
11111  
100001 
*/

#include <iostream>
using namespace std;

int main()
{
    // Get user input
    int n;
    cout << "Enter the number of rows you want to print" << endl;
    cin >> n;

    // Logic

    // Loop for rows
    for (int i = 1; i <= n; i++)
    {
        //logic to print rows contains only '1'
        if (i % 2 != 0 || i == 2)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "1";
            }
        }
        else
        {
            // Logic to print leftover rows that cotains 1 in the first and last position and 0 in between

            for (int k = 1; k <= i; k++)
            {
                if (k == i || k == 1)
                {
                    cout << "1";
                }
                else
                    cout << "0";
            }
        }

        cout << endl;
    }

    return 0;
}