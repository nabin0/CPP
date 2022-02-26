#include<iostream>

int max(int a, int b){return (a > b)?a:b;}

int knapsack(int bagSize, int *val, int *wt, int n){
    if(n==0 or bagSize == 0){ // Base case
        return 0;
    }

    if(wt[n-1] > bagSize) // If the n-1th item weight is greater than size of bag cannot insert it
        return knapsack(bagSize, val, wt, n-1);
    else // Recursive call to knapsack considering the current item and not considering the current item
        return max(val[n-1] + knapsack(bagSize-wt[n-1], val,wt, n-1), knapsack(bagSize, val,wt,n-1));
}

int main(){
    int val[]{10,20,100,100};
    int wt[]{10,20,50,100};
    int n = sizeof(val)/sizeof(val[0]);
    int bagSize  = 120;
    std::cout << knapsack(bagSize,val,wt,n);
    return 0;
}