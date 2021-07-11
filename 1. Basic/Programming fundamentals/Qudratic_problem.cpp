/*
Problem Name: Revising Quadratic Equations
Problem Difficulty: 1
Problem Constraints: -100 <= a, b, c <= 100
Problem Description:
Given coefficients of a quadratic equation , you need to print the nature of the roots (Real and Distinct , Real and Equal or Imaginary) and the roots. <br>
If Real and Distinct , print the roots in increasing order. <br>
If Real and Equal , print the same repeating root twice <br>
If Imaginary , no need to print the roots.

Note : Print only the integer part of the roots.
Input Format: First line contains three integer coefficients a,b,c for the equation ax^2 + bx + c = 0.
Sample Input: 1 -11 28
Output Format: Output contains one/two lines. First line contains nature of the roots .The next line contains roots(in non-decreasing order) separated by a space if they exist. If roots are imaginary do not print the roots.
Output the integer values for the roots.
Sample Output: Real and Distinct
4 7
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int a, b, c;
    cin >> a >> b >> c;

    // Calculating value of sqroot part
    int d = b * b - 4 * a * c;
    d = sqrt(d);

    // Condition checking for
    if (d == 0)
    {
        cout << "Roots are equal" << endl;
    }
    else if (d > 0)
    {
        cout << "Roots are real and distinct" << endl;

        // calculating value of roots
        int x1 = (-b - d) / (2 * a);
        int x2 = (-b + d) / (2 * a);
        cout << "The two roots are: " << x1 << " and " << x2 << endl;
    }
    else
    {
        cout << "Roots are imaginary" << endl;
    }

    return 0;
}