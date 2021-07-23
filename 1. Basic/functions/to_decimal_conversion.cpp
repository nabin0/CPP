#include <iostream>
using namespace std;

// Binary to decimal
int binTdec(int n)
{
    int decVal = 0, pval = 1;
    while (n > 0)
    {
        int lastDigit = n % 10;
        decVal = decVal + lastDigit * pval;
        pval *= 2;
        n /= 10;
    }
    return decVal;
}

// Octal to decimal
int octTdec(int n)
{
    int octVal = 0, pval = 1;
    while (n > 0)
    {
        int lastDigit = n % 10;
        octVal = octVal + lastDigit * pval;
        pval *= 8;
        n /= 10;
    }
    return octVal;
}

// Hexa to decimal
int hexaTdec(string s)
{
    int hexVal = 0, pval = 1;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            hexVal += pval * (s[i] - '0'); // subtracting '0' from any char value gives wnted int value like '8' - '0' =8
        }
        else if ((s[i] >= 'A') && (s[i] <= 'F')) 
        {
            hexVal += pval * (s[i] - 'A' + 10); // let s[i] = 'C'. so 'C' - 'A' gives 2 and then adding 10 to 2 =12, which is value of 'C' for hexa decimal form
        }

        pval *= 16;
    }

    return hexVal;
}

int main()
{

    // Binary to decimal
    // int n;
    // cin>>n;
    // cout<<"Dec value of given binary number is "<<binTdec(n)<<endl;

    // Octal to decimal
    // int n;
    // cin>>n;
    // cout<<"Dec value of given Octal number is "<<octTdec(n)<<endl;

    // Hexa to decimal
    string s;
    cin >> s;
    cout << "Dec value of given Hexa number is " << hexaTdec(s) << endl;
    return 0;
}