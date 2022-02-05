#include<iostream>
using namespace std;

int sellBuyStockTwice(int arr[], int n){

    // Create a profit array and init it with 0
    int *profit = new int(n);
    for (int i = 0; i < n; i++)
    {
        profit[i] = 0;
    }

    // now traverse arr from right to left to get max profit for one time buy ans sell
    int maxPrice = arr[n-1];
    for (int i = n-2; i >=0; i--)
    {
        if(maxPrice < arr[i]){
            maxPrice = arr[i];
        }

        profit[i] = max(profit[i+1], maxPrice-arr[i]); // Stores max price till in arr[i]
    }
    
    // Again iteratae the array from left to right this time it will give max profit if we sell and buy twice in a day
    int minPrice = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(minPrice> arr[i]){
            minPrice = arr[i];
        }
        profit[i] = max(profit[i-1], profit[i] + (arr[i] -minPrice)); 
    }
    int result = profit[n-1];
    delete(profit);
    return result;
}

int main(){
    int arr[] {1,3,4,2,5,6};
    int n = sizeof(arr)/sizeof(arr[n]);
    cout<<sellBuyStockTwice(arr,n);
    return 0;
}