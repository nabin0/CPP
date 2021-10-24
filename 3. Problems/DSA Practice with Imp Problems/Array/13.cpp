#include<iostream>
#include<climits>
using namespace std;

int kadanesAlgo(int *arr, int n){
    int maxSum = INT_MIN;
    int tempSum = 0;

    int startIdx = 0, endIdx = 0;

    for (int i = 0; i < n; i++)
    {
        tempSum += arr[i];
        if(tempSum < 0){
            tempSum = 0;
        }

    maxSum =  max(tempSum, maxSum);
    }
    return maxSum;
}

int main(){
    int arr[] = {1,1,4,5,-8,-6,13,4,-3,2,3};
    int n = sizeof(arr)/sizeof(int);
    cout<<kadanesAlgo( arr, n);
    return 0;
}