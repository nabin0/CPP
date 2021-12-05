#include<iostream>
using namespace std;

int largestSum(int *arr, int n){
    int maxSum = 0;
    int tempSum= 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            tempSum = 0;
            for (int k = i; k <= j; k++)
            {
                tempSum+=arr[k];
            }
            maxSum = max(maxSum, tempSum);
        }    
    } 
    return maxSum;
}

int kdanesAlgo(int *arr, int n){
    int maxSum = 0;
    int tempSum =0;
    for (int i = 0; i < n; i++)
    {
        if(tempSum < 0){
            tempSum = 0;
        }
        tempSum += arr[i]; t
        maxSum = max(maxSum, tempSum);
    }
    return maxSum;
}

int main(){
    int arr[] = {1,3,5,6,8,9};
    int s = sizeof(arr)/sizeof(arr[0]);
    cout<<largestSum(arr,s)<<endl;
    cout<<kdanesAlgo(arr, s);
    return 0;
}