#include <iostream>
using namespace std;
//Logic: shift position bit bt 1 and app;y and operation with n. then we will get the bit present at that position.
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int main()
{

    cout << getBit(5, 1);
    return 0;
}