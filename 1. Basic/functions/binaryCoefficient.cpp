// n
//   C
//     r  = (n!)/((n-r)!(r!))

#include <iostream>
using namespace std;

int factorial(int n)
{
    int fct = 1;
    if (n == 0)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        fct = fct * i;
    }
    return fct;
}

int main()
{
    int n, r;
    cin >> n >> r;

    int bincoff = factorial(n)/(factorial(n-r) * factorial(r));
    cout<<bincoff<<endl;
    return 0;
}