#include <iostream>
using namespace std;

void reverse(string str, int s, int e)
{

    if (s > e)
    {
        return;
    }

    int temp = str[s];
    str[s] = str[e];
    str[e] = temp;

    reverse(str, s + 1, e - 1);
}

int main()
{
    string str = "Helllo";
    int n = str.length();
    reverse(str, 0, n - 1);
    cout << str << endl;

    return 0;
}