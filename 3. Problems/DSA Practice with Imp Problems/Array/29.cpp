#include<iostream>
using namespace std;

int rainwaterTrapping(int *arr, int n){
    int left[n];
    int right[n];

    left[0] =arr[0];
    right[n-1] = arr[n-1];
    
    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i-1]);
    }
    for (int i = n-2; i >=0; i--)
    {
        right[i] = max(arr[i], right[i+1]);
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){

        res += min(left[i], right[i]) - arr[i];
    }
    return res;
}

int main(){
    int arr[] = {2,0,3,0,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<rainwaterTrapping(arr, n)<<endl;
    return 0;
}