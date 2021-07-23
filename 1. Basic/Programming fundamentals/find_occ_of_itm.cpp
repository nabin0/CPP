/*
Problem Name: Count Digits(occurance of a digit)

*/

#include <iostream>
using namespace std;

int find_occurance(int n, int digit)
{
    int res = 0;
    while (n != 0)
    {
        int t = n % 10;
        if (t == digit)
        {
            res++;
        }
        n = n / 10;
    }
    return res;
}

int main()
{
    int n, digit;
    cout << "Enter the number and digit ..." << endl;
    cin >> n >> digit;

    cout << "The occurance of given digit is: " << find_occurance(n, digit) << endl;

    return 0;
}