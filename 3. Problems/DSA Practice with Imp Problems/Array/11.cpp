#include<iostream>
using namespace std;

int findDuplicates(int * arr, int n){
    int dupEnd = 100;
    int dup[dupEnd];

    for (int i = 0; i < 100; i++)
    {
        dup[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        dup[arr[i]]++;

        if(dup[arr[i]] > 1){
            return i;
        }
    }
    return -1;
    
}

int main(){
    int arr[] = {2,3,5,6,9,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"the duplicate element is at index :"<<findDuplicates(arr,size);
    return 0;
}