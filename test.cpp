#include<iostream>
#include<string>
using namespace std;

void solve(string ip, string op){
    if(ip.length() == 0){
        cout  << op << endl;
        return;
    }

    string s1 = op;
    string s2 = op;

    s2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip,s1);
    solve(ip,s2);
}
int main(){
    string s = "ABC";
    solve(s, "");
    return 0;
}