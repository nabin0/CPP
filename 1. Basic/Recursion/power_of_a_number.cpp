#include <iostream>
using namespace std;

int power(int n, int p) // n space and n time
{
    if (p == 0)
    {
        return 1;
    }

    int lastPow = power(n, p-1);
    return lastPow * n;
}

double _power(int n, int _p){ // Logn complexity
    double res = 1;
    int p = _p < 0? -1 * _p : _p;

    while(p > 0){
        if(p %2){
            res = res * n;
            p = p - 1;
        }else{
            p = p / 2;
            n = n*n;
        }
    }
    if(_p < 0)
        res = 1.0 / res;
    return res;
}

int main()
{
    int n, p;
    cin >> n >> p;

    // cout << "The result is : " << power(n, p) << endl;
    cout << "The result is : " << _power(n, p) << endl;
    return 0;
}