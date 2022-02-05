#include<iostream>
using namespace std;

bool findTriplet(int *arr, int n, int sum){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(arr[i] +arr[j] +arr[k] == sum){
                    cout<<"the triplet is: "<<i<<" "<<j<<" "<<k<<endl;
                    return true;
                }
            }
            
        }
        
    }
    return false;
}

// Array item order should not be changed
bool tripletSubarrayEqualsToSum(int *arr, int n, int sum){
    int res = 0;
    int i = 0,j =0;
    for (i = 0; i < n; i++)
    {
         res = 0;
        for(int j = i; j < i+3 && j < n; j++){
            res+=arr[j];
            if(j >= n){
                return false;
            }
        }
        if(res == sum){
            cout<<"index : "<<i<<" -> "<<i+2<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] {1,4,5,-3,1,15,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<tripletSubarrayEqualsToSum(arr,n,3)<<endl;
    cout<<findTriplet(arr,n,3);
    return 0;
}