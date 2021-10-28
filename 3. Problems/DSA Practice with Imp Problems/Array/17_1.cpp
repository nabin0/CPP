#include<iostream>
using namespace std;

// Bruteforce method
int sellStock(int *arr, int n ){
    int maxProfit =0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            maxProfit = max(maxProfit, arr[j] -arr[i]);
        }
        
    }
    return maxProfit;
}

//Optimissed with storing maximum sell price 
int sellStockOptimisedWithStore(int *arr, int n){

    int temp[n];
    int tempMax = arr[n-1];
    int maxProfit  = 0;
    for (int i = n-1; i >= 0; i--)
    {
        tempMax = max(arr[i], tempMax);
        temp[i] = tempMax;
    }
    
    for (int i = 0; i < n; i++)
    {
        maxProfit = max(temp[i] -arr[i], maxProfit);
    }
    return maxProfit;
}

// Optimised space and time O(n)
int maximumProfit(int *arr, int n){
    int maxProfit = 0;
    int minBuyPrice = arr[0];

    for (int i = 0; i < n; i++)
    {
        minBuyPrice = min(arr[i], minBuyPrice);
        maxProfit = max(arr[i] - minBuyPrice, maxProfit);
    }
    return maxProfit;
}


int main(){

    int arr[] = {3,1,4,8,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sellStock(arr,n)<<endl;
    cout<<sellStockOptimisedWithStore(arr,n)<<endl;
    cout<<maximumProfit(arr,n)<<endl;

    return 0;
}