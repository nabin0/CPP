/*
Problem Name: Simple Input
Problem Difficulty: 1
Problem Constraints: All numbers input are integers between -1000 and 1000.
Problem Description:
Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.
Input Format: A list of integers to be processed
Sample Input: 1
2
88
-100
49
Output Format: Print all the numbers before the cumulative sum become negative.
Sample Output: 1
2
88

*/

#include <iostream>
using namespace std;

int main()
{
    // no of element you want to enter
    int n;
    cin >> n;

// Get element and declare sum var to store value of sum for each iteration
    int elem;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        if (sum >= 0)
        {
            cout << elem << endl;
            sum = sum + elem;
        }
        else
        {
            cout << "Cumulative sum is negative" << endl;
            break;
        }
    }

    return 0;
}