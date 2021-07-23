/*
Problem Name: Check prime

*/

#include <iostream>
using namespace std;

int main()
{

    long long int n;
    cout << "Enter the number:" << endl;
    cin >> n;

    bool isPrime = false;
    for (int i = 2; i < n; i++)
    {
        if (n % i != 0)
        {
            isPrime = true;
        }
        else
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << n << " is Prime Number" << endl;
    }
    else
        cout << n << " is not a prime number" << endl;

    return 0;
}