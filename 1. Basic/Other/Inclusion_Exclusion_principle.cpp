//This principle is useful when we have problem where we have to find no of ways to do something
// for eg. we want to find numbers divisible by 5 and 7 in range 0 to 40. so here n = 40, a= 5, b= 7

#include <iostream>
using namespace std;

int divisible(int n, int a, int b)
{
    int a1 = n / a;
    int a2 = n / b;
    int a3 = n / (a * b);

    return a1 + a2 - a3;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    cout << divisible(n, a, b);
    return 0;
}