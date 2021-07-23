/*
Qudratic equation roots(input values a b c)
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