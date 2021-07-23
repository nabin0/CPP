#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int lastPow = power(n, p-1);
    return lastPow * n;
}

int main()
{
    int n, p;
    cin >> n >> p;

    cout << "The result is : " << power(n, p) << endl;
    return 0;
}