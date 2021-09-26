#include<iostream>
using namespace std;

int find_largest_word(string s){
    int templen = 0; // to store length of word temporarily
    int maxlen = 0;

    int i = 0;
    while(s[i] != '\0'){ //Loop until end of the string
        if(s[i] != ' '){ //count until space ' ' encounters
            templen++;
            i++;
        } else if(s[i] == ' ' or s[i] == '\0'){ // do this when space or end of string encounters
            maxlen = templen;
            templen = 0;
            i++;
        }
    }

return maxlen;
}

int main(){
    string s= "Hello Iam a TestingS String";
    cout<<find_largest_word(s);
    return 0;
}