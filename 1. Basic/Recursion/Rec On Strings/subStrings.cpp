#include <iostream>
using namespace std;

void substr(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    substr(str.substr(1), ans + ch);
    substr(str.substr(1), ans);
}

int main()
{

    substr("ABC", "");

    return 0;
}