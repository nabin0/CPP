#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    // Get input from
    cout << "enter number of star you want to print" << endl;
    cin >> n;

// Logic for printing stars
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) or (i == 2) and (j % 4 == 0))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}