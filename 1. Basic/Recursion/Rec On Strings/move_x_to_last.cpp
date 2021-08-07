#include <iostream>
using namespace std;

string moveToLast(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string st = moveToLast(s.substr(1));

    if (ch == 'x')
    {
        return (st + ch);
    }
    else
    {
        return (ch + st);
    }
    return st;
}

int main()
{
    string st = "dfkjhxkhckjhkjcxxxjkx";
    cout << moveToLast(st);
    return 0;
}