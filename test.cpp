#include<iostream>
using namespace std;

struct ar{
    int data;
};

ar arr[]={1,2,3,4,5,6};
int main(){
    cout<<arr[2].data<<endl;
    return 0;
}