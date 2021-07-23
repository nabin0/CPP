#include<iostream>
using namespace std;

// Iteration method
int sumOfnIter(int n){
int sum = 0;
for (int i = 1; i <= n; i++)
{
    sum += i;
}
return sum;
}


// Formulae method
int sumOfnFormula(int n){
    int sum = (n*(n +1))/2;
    return sum;
}
int main(){
int n;
cin>>n;

cout<<"The sum till n is "<<sumOfnIter(n)<<endl;
cout<<"The sum till n is "<<sumOfnFormula(n)<<endl;

return 0;
}