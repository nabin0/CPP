
#include <iostream>
using namespace std;

int main()
{

    // Declaring variables
    int dec_val = 10;
    string oct_val = "";

    // Logic
    while (dec_val != 0)
    {
        int r = dec_val % 8;
        dec_val /= 8;
        char c = r + '0';
        oct_val = c + oct_val;
    }

    // outputting value
    cout << "The Octal value is: " << oct_val << endl;

    return 0;
}