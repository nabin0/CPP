#include <iostream>
using namespace std;

int updateBit(int n, int pos, int updateVal)
{
    int mask = ~(1 << pos);
    int clVal = n & mask;
    return (clVal | (updateVal << pos));
}

int main()
{
    cout << updateBit(5, 1, 1) << endl;
    return 0;
}