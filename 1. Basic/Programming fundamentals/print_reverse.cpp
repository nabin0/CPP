/*
Problem Name: Print reverse

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