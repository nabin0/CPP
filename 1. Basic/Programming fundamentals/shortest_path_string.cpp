#include <iostream>
using namespace std;

int main()
{

    // Get string input
    char ch;
    ch = cin.get();

    // Declaring coordinates
    int x = 0;
    int y = 0;

    while (ch != '\n')
    {

        if (ch == 'e' or ch == 'E')
        {
            x++;
        }
        else if (ch == 'w' or ch == 'W')
        {
            x--;
        }
        else if (ch == 'n' or ch == 'N')
        {
            y++;
        }
        else if (ch == 's' or ch == 'S')
        {
            y--;
        }
        else
        {
            cout << "Please Check Your input." << endl;
        }
        ch = cin.get();
    }

// Printing co-ordinates value
    cout << "Value of x: " << x << " and value of y: " << y << ". So the coordonates are (" << x << "," << y << ")" << endl;
    return 0;
}