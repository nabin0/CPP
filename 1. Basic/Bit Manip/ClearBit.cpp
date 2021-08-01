#include <iostream>
using namespace std;

int clearBit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

int main()
{
    cout << clearBit(12, 2) << endl;
    return 0;
}