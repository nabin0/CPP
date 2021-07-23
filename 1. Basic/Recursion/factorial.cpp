#include<iostream>
using namespace std;

int factorial(int n){

if(n == 0){
    return 1;
}

int lstFact = factorial(n-1);
return n*lstFact;
}

int main(){
int n;
cin >>n;

cout<<"The factorial of given number is: "<<factorial(n)<<endl;
return 0;
}