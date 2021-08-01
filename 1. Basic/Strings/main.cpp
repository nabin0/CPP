#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{

    //String declaration and initialization
    // string str = "Hello How are you doing";

    // string str;
    // getline(cin, str); //Sting input takes whole string

    // cin >> str; //Reads first word of string only

    // cout << str;

    //Builtin string function
    string str = "Hello How are you doing.";
    string str1 = "i hope you are doing well.";

    // string appendedstr = str.append(str1); //appends tow strings
    // cout<<appendedstr<<endl;

    // str.clear(); //clears the data of string
    // cout<<str<<endl;

    // str.assign("dkf"); //To assign new value to the string

    // int size = str.size(); //Size of string(length of str)
    int len = str.length();

    // cout << str.find("llo") << endl; //Returns start index if finds the value

    // cout<<str.empty()<<endl; //Returns boolean value 0 if not empty

    // cout<<str.insert(3,2, 'Y')<<endl;  //Inset char val at specified position insert(position index, repeat time, char );

    cout << str.compare(str1) << endl;

    return 0;
}