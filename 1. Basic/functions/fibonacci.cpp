#include <iostream>
using namespace std;

// Func for fibonacci series
void fib(int n)
{
    int a = 0, b = 1;
    int val = 0;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++)
    {
        val = a + b;
        a = b;
        b = val;
        cout << val << " ";
    }
}

int main()
{
    // user input
    int n;
    cin >> n;

    // Invoking function
    fib(n);
    return 0;
}