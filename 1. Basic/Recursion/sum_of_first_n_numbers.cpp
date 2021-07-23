#include<iostream>
using namespace std;

int sum(int n){
    if(n == 0){
        return 0;
    }
    int lastSum= sum(n-1);

    return lastSum + n;
}

int main(){

int n;
cin>>n;

cout<<"The sum is : "<<sum(n)<<endl;
return 0;
}