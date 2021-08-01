//Find primes till n using seive of eratothenes
#include <iostream>
using namespace std;

void primeSeive(int n)
{
    //Initialize array
    int prime[100] = {0};

    //Put value 1 if value is multiple of i
    for (int i = 2; i * i < n; i++)
    {
        for (int j = i * i; j <= n; j = j + i)
        {
            prime[j] = 1;
        }
    }

    //Print values whose value is not changed those are not multiple of the i
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{

    int n;
    cin >> n;
    primeSeive(n);
    return 0;
}