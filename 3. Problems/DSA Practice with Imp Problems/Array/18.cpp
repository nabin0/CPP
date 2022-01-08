// the problem is to find numbers of pairs that sums equals to the value of sum given as inputs
#include<iostream>
#include<unordered_map>
using namespace std;

// bruteforce approach
int noOfPairsBruteForce(int arr[], int n, int sum){
    int noOfPairs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if((arr[i] +arr[j]) == sum){
                noOfPairs++;
            }
        }
    }
    return noOfPairs;
}

//optimised approach
int noOfPairsOptimisedApproach(int *arr, int n, int sum){
    
    unordered_map<int , int> m; // create and store count of the array elements on the map
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    int doubleCount = 0; // double count beause we are going to count same pair 2 times e.g: (1 , 3) we count 1 for val 1 and agin 1 time for val 3 

    // iterate all the elements of array and add their count value to doublecount
    for (int i = 0; i < n; i++)
    {
        // here m[sum-arr[i]] gives the count of that item present in array. this item will be considered 2 times that's why 
        // WE have to divide double count later for eg. [1,3 ] here 1 will be added to double count doubleCount+=m[sum-arr[i]] when i = 0 and again 1 will be added when i =1

        doubleCount+=m[sum-arr[i]];

        if(sum-arr[i] == arr[i]){ // When the element half of the sum is in the arrr for eg[1,2,3] where sum=4 , here 2 is not making any pair but still is is going 
         //to be count. if [1,2,3,2] is case then count of m[2] =2; for each two 2 will be added into doublecount so to avoid this the count is decreased
            doubleCount--;
        }
    }
    return doubleCount/2;
}

int main(){
    int arr[] = {1,3,4,5,6,7,3,6,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<noOfPairsBruteForce(arr, n, 4)<<endl;
    cout<<noOfPairsOptimisedApproach(arr, n, 4)<<endl;

    return 0;
}