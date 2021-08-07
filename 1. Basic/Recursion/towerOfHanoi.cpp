#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char hlpr, char dest)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, src, dest, hlpr);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n - 1, hlpr, src, dest);
}

int main()
{
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}