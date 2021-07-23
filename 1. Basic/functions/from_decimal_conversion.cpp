#include <iostream>
using namespace std;

// Decimal to Binary conversion
int decimalToBinary(int n)
{
    int p = 1; // for conversion in this case =:> 2^someVal
    int ans = 0;

    while (p <= n)
    {
        p *= 2;
    }
    p /= 2;
    while (p > 0)
    {
        int coeff = n / p;
        n -= coeff * p;
        ans = ans * 10 + coeff;
        p /= 2;
    }
    return ans;
}

// Decimal to Octal conversion
int decimalToOcta(int n)
{
    int p = 1;
    int ans = 0;

    while (p <= n)
    {
        p *= 8;
    }
    p /= 8;
    while (p > 0)
    {
        int coeff = n / p;
        n -= coeff * p;
        ans = ans * 10 + coeff;
        p /= 8;
    }
    return ans;
}

// Decimal to hexadecimal conversion
string decimalToHexa(int n)
{
    string sum = "";
    int x = 1;

    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;
    while (x > 0)
    {
        int d = n / x;

        if (d >= 0 && d <= 9)
        {
            sum = sum + to_string(d);
        }
        else
        {
            char c = 'A' + (d - 10);
            sum.push_back(c);
        }
        n -= x * d;
        x /= 16;
    }
    return sum;
}
int main()
{
    // Decimal to Binary conversion

    // int n;
    // cout<<"Enter the decimal Number"<<endl;
    // cin >> n;
    // int res = decimalToBinary(n);
    // cout << res << endl;

    // Decimal to Octal conversion
    // int n;
    // cout << "Enter the decimal Number" << endl;
    // cin >> n;
    // int res = decimalToOcta(n);
    // cout << res << endl;

    // Decimal to Hexadecimal conversion
    int n;
    cout << "Enter the decimal Number" << endl;
    cin >> n;
    cout << decimalToHexa(n) << endl;

    return 0;
}