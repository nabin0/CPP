#include<iostream>
using namespace std;

void rotateArr(int arr[], int n){
    int temp = arr[n-1];

    for (int i = n-1; i >=0; i--)
    {
        arr[i] = arr[i-1];
    }arr[0] =temp;
}

int main(){
    int arr[] = {2,5,4,3,7,8};
    rotateArr(arr,6);

    for(auto i : arr){
        cout<<i<<" ";
    }

    return 0;
}