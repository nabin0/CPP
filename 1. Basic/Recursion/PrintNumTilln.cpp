#include <iostream>
using namespace std;

//Prints in increasing order
void incNums(int n)
{
    if (n == 0)
    {
        return;
    }
    incNums(n - 1);
    cout << n << " ";
}

//prints in decreasing order

void decNums(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    decNums(n - 1);
}

int main()
{
    int n;
    cin >> n;

    //Invoking functions
    incNums(n);
    cout << endl;
    decNums(n);
    return 0;
}