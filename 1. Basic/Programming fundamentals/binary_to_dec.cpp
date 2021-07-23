/*
Problem Name: Binary to decimal

*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of lines you want to enter." << endl;
    int n;
    cin >> n;

    int n_arr[n];
    // Get binary rows
    for (int i = 0; i < n; i++)
    {
        cin >> n_arr[i];
    }

    // Initializing varriables for logic
    int base = 1, temp, dec_val;

    for (int i = 0; i < n; i++)
    {
        temp = n_arr[i];
        dec_val = 0;
        base = 1;

        // Logic
        while (temp)
        {
            int last_digit = temp % 10;
            temp = temp / 10;
            dec_val += last_digit * base;
            base = base * 2;
        }

        // outputting value
        cout << "The decimal value is: " << dec_val << endl;
    }

    return 0;
}