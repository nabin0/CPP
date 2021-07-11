/*
Problem Name: Print reverse
Problem Difficulty: 1
Problem Constraints: 0 <= N <= 1000000000
Problem Description:
Take N as input, Calculate it's reverse also Print the reverse.
Input Format: 
Sample Input: 123456789
Output Format: 
Sample Output: 987654321
*/

#include <iostream>
using namespace std;

int main()
{

    // Taking n from input
    int n, rev = 0, rem;
    cout << "Enter the value to be reversed." << endl;
    cin >> n;

    // reversing input value
    int total;
    while (n != 0)
    {
        // Logic
        rem = n % 10; //calculates reminder
        rev = rev * 10 + rem; 
        n /= 10;
    }
    cout << rev << endl;

    return 0;
}