#include<iostream>
#include<climits>
using namespace std;

int maxProductSubarray(int *arr, int n){
    int maxProduct = 1;
    int tempProd = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            tempProd = 1;
            for (int k = i; k <= j; k++)
            {
                tempProd *= arr[k];
            }
            maxProduct = max(maxProduct, tempProd);
        }
        
    }
    return maxProduct;
}

void subarray(int *arr, int n){
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        for (int j = i+1; j < n; j++)
        {
            mul*=arr[j];
            res = max(res,mul);
        }
    }
    cout<<res<<endl;
}

int main(){
    int arr[] = {1,-2,-3,0,7,-8,-2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProductSubarray(arr,n)<<endl;
    subarray(arr, n);
    return 0;
}