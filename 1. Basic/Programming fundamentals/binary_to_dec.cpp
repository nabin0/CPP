/*
Problem Name: Von Neuman Loves Binary
Problem Difficulty: 1
Problem Constraints: N<=1000
Digits in binary representation is <=16.
Problem Description:
Given a binary number ,help Von Neuman to find out its decimal representation.
For eg 000111 in binary is 7 in decimal.
Input Format: The first line contains N , the number of binary numbers.
Next N lines contain N integers each representing binary represenation of number.
Sample Input: 4
101
1111
00110
111111
Output Format: N lines,each containing a decimal equivalent of the binary number.
Sample Output: 5
15
6
63
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