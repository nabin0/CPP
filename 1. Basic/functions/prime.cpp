// Problem: find whether the numbers bteween given range are prime are not
#include <iostream>
#include <cmath>
using namespace std;

// Function for checking number is prime or not
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{

// Taking user input
    int n1, n2;
    cin >> n1 >> n2;

    for (int i = n1; i <= n2; i++)
    {
        if (isPrime(i))
        {
            cout << i << " is a Prime Number" << endl;
        }
        else
            cout << i << " is Not Prime" << endl;
    }
    return 0;
}