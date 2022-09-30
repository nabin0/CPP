//Find primes till n using seive of eratothenes
#include <iostream>
using namespace std;

void primeSeive(int n)
{
    //Initialize array
    int prime[n] = {0};

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

void primeSeive1(int n){
    int arr[n+1]{0};

    for(int i = 2; i*i <= n; i++){
        if(arr[i] == 0){
            for(int j = i; j*i <= n; j++){
                arr[j*i] = 1;
            }
        }
    }

    // Print result
    for(int i = 2; i <= n; i++){
        if(arr[i] == 0)
            cout << i << ' ';
    }cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number: " ;
    cin >> n;
    primeSeive(n);
    primeSeive1(n);
    return 0;
}