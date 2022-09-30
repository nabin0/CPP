#include<bits/stdc++.h>
using namespace std;


void TOH(int n, char source, char destination, char helper){
    if(n == 1){
        cout << "Move " << n << " from " << source << " to " << destination<< endl;
        return;
    } 

    TOH(n-1, source, helper, destination);
        cout << "Move " << n << " from " << source << " to " << destination<<endl;
    TOH(n-1, helper, destination, source);
}

int main(){
    char source = 'A', destination = 'B', helper = 'H';
    TOH(10, source, destination, helper);
    return 0;
}