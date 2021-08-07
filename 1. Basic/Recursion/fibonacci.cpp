// Problem: find nth fibonacci number
#include<iostream>
using namespace std;

int fibonacci(int n){
    int a = 0;
    int b= 1;

    if(n ==1 || n == 0){
        return n;
    }
    
    int lstFib = fibonacci(n-1) + fibonacci(n-2);
    return lstFib;
}

int main(){
int n;
cin>>n;

cout<<fibonacci(n)<<endl;
return 0;
}