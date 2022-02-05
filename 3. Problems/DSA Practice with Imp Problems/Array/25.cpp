#include<iostream>
#include<unordered_map> 
using namespace std;

void findMoreOccuredElements(int arr[], int n, int k){
    int nrk = n/k; 
    int count[100];
    for (int i = 0; i < 100; i++) 
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) // ccounting the occurance of the items in the arr ans store them into count array
    {
        count[arr[i]]++;
    }
    cout<<"the elements that occured in array more than "<<nrk<<" time: "<<endl;
    for (int i = 0; i < 100; i++)
    {
        if(count[i] > nrk){
            cout<<i<<" ";
        }
    } cout<<endl;
}

void findOccurance(int *arr, int n , int k){
    int ndk = n/k;
    unordered_map<int ,int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for(auto i:count){
        if(i.second > ndk){
            cout<<i.first<<" ";
        }
    }
}

int main(){
    int arr[] = {1,1,2,3,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    findMoreOccuredElements(arr, n,3);
    findOccurance(arr,n,3);
    return 0;
}