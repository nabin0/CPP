//Method 1 (normal method by sorting array)

#include<iostream>
#include<algorithm>
using namespace std;

void kthMaxMin(int arr[], int n, int k){
    sort(arr, arr+n);
    cout<< " kth smallest : " << arr[k-1] <<"\nKth largest : "<< arr[n-k];

}


int main(){
    int arr[] = {3,4,1,5,8,2,7,9};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 2;
    kthMaxMin(arr,n,k);
    return 0;
}

//Doing by using heap [TODO]