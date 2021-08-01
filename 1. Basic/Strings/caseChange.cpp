#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    string st = "Helllo iam in lower case";

    //buitin function

    cout << "Builtin functoion>>>" << endl;
    transform(st.begin(), st.end(), st.begin(), ::toupper); //transform(starting iterator, ending iterator, change case from iterator, case to change)
    cout << st << endl;
    transform(st.begin(), st.end(), st.begin(), ::tolower);
    cout << st << endl;

    cout << "\nCostum logic\n";

    // to see difference between a and A
    // cout<<'a'-'A'<<endl; //We will get 32 so to get uppercase of small case letter we have to minus 32

    //logic to convert into uppercase
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] >= 'a' and st[i] <= 'z')
        {
            st[i] -= 32;
        }
    }
    cout << st << endl;

    //Logic to convert into lowercase
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] >= 'A' && st[i] <= 'Z')
        {
            st[i] += 32;
        }
    }
    cout << st << endl;

    return 0;
}