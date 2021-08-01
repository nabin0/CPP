#include <iostream>
using namespace std;

int noOfOnes(int n)
{
    int ctr = 0;
    while (n)
    {
        n = (n & (n - 1));
        ctr++;
    }
    return ctr;
}

int main()
{
    cout << noOfOnes(5) << endl;
    return 0;
}