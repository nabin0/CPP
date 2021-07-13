/*
Problem Name: Count Digits
Problem Difficulty: None
Problem Constraints: 0 <= N <= 1000000000 
0 <= Digit <= 9
Problem Description:
Take the following as input.  
A number  
A digit  
Write a function that returns the number of times digit is found in the number. Print the value returned.
Input Format: Integer (A number) 
Integer (A digit)
Sample Input: 5433231 
3
Output Format: Integer (count of times digit occurs in the number)
Sample Output: 3
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