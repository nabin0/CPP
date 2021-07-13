/*

Problem Name: Print Series
Problem Difficulty: None
Problem Constraints: 0 < N1 < 100 
0 < N2 < 100
Problem Description:
Take the following as input.

A number (N1)  
A number (N2)  
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.
Input Format: 
Sample Input: 10 
4
Output Format: 
Sample Output:
 5 
11 
14 
17 
23 
26 
29 
35 
38 
41
*/


#include <iostream>
using namespace std;

int main()
{

    // Grtting Input
    int n1;
    cout << "Enter the number of items you want to print." << endl;
    cin >> n1;
    cout << "Enter the Number whose multiple won't be printed." << endl;
    int n2;
    cin >> n2;

    // Logic to print itms
    int limit = 1, n = 1;
    while (limit <= n1)
    {
        int num = (3 * n + 2);
        if (num % n2 != 0)
        {
            cout << num << endl;
            limit++;
        }
        n++;
    }

    return 0;
}