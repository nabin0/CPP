#include <iostream>
using namespace std;


void primeFactorization(int n)
{
    //Declare and init arr with 0
    int spf[100] = {0};

    //Put spf(Smallest Prime Factor) values in corresponding index
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    // PrintArr(spf, 100);

    while (n != 1)
    {
        cout << n << " ";
        n = n / spf[n];
    }
}

void primeFactor(int n){
    int arr[n+1]{0};
    for(int i = 2; i*i <= n; i++){
        if(arr[i] == 0){
            for(int j = i; j*i <= n; j++){
                if(arr[j*i] == 0)
                    arr[j*i] = i;
            }
        }
    }
    while(n != 1){
        cout << n << ' ' ;
        n = n/ arr[n];
    }cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // n = 42;
    // primeFactorization(n);
    primeFactor(n);
    return 0;
}