#include <iostream>
using namespace std;

void substr(string str, string ans) // Wrong output
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

void sub_string(const string &s, string ans, int pos){
    if(pos == s.length()){
        if(ans.length() > 0)
        cout << ans << endl;
        return;
    }

    char ch = s[pos];
    if(pos == 0 || s[pos - 1] == ans[ans.length()-1] || ans.length() == 0)
        sub_string(s, ans + ch, pos + 1);
    sub_string(s, ans, pos + 1);
}

int main()
{

    // substr("ABC", "");
    sub_string("", "", 0);

    return 0;
}