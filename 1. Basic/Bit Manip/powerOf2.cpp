#include <iostream>
using namespace std;

bool isPowerOf2(int n)
{
    return (n && !(n & (n - 1)));
}
int main()
{
    cout << boolalpha << isPowerOf2(5) << endl;
    return 0;
}