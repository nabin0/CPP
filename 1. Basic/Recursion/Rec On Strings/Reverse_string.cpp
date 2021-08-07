#include <iostream>
using namespace std;

void reverse(string str)
{
    if (str.length() == 0) //Base case
    {
        return;
    }
    
    string ros = str.substr(1);
    reverse(ros);
    cout << str[0];
}

int main()
{
    string st = "Hello How are you";
    reverse(st);
    cout << endl;
    return 0;
}