#include <iostream>
using namespace std;

int factorial(int n)
{
    int factVal = 1;
    if (n == 0)
    {
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        factVal *= i;
    }
    return factVal;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << factorial(i) / (factorial(i - j) * factorial(j)) << " ";
        }
        cout << endl;
    }

    return 0;
}