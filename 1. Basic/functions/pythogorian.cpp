// Problem : check whether given is pythogorian triplet

#include <iostream>
using namespace std;

bool checkPygor(int a, int b, int c)
{
    int m = max(a, max(b, c));
    int n, o;
    if (m == a)
    {
        n = b;
        o = c;
    }
    else if (m == b)
    {
        n = a;
        m = c;
    }
    else
    {
        n = a;
        o = b;
    }

    if (m*m == n*n + o*o)    
    {
       return true;
    }
    return false;
    
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

if (checkPygor(a,b,c))
{
    cout<<"Is pythogorian triplet"<<endl;
}
else{
    cout<<"Is not a pythogorian triplet"<<endl;
}


    return 0;
}