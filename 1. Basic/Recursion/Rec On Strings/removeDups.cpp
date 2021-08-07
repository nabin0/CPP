#include <iostream>
using namespace std;

string removeDup(string str)
{
    if (str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    string res = removeDup(str.substr(1));
    if (res[0] == ch)
    {
        return res;
    }
    else
    {
        return (ch + res);
    }
    return res;
}

int main()
{
    string st = "aaaannnndddddffffeeeesss";
    cout << removeDup(st) << endl;
    return 0;
}