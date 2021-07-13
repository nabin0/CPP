/*
Problem Name: Check prime
Problem Difficulty: None
Problem Constraints: 2 < N <= 1000000000
Problem Description:
Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".
Input Format: 
Sample Input: 3
Output Format: 
Sample Output: Prime
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