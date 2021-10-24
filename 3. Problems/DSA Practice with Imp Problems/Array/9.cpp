#include<iostream>
#include<algorithm>
using namespace std;

int min_height(int arr[], int n , int k){

    if(n == 1){ //if only one height is given return zero because there is no other value to compare
        return 0;
    }

    sort(arr,arr+n); //sorting the given array

    int max_diff = arr[n-1] - arr[0]; //maximum difference in between the tower i.e largest height - smallest height
    int maximum = arr[n-1]-k; //Let maximum height is the last height - k
    int minimum = arr[0] +k; //smallest height be arr[0] + k because we have to either add or sub k and arr[0] is the smallest height
    int temp = 0;

    if(minimum > maximum){ 
        temp = maximum;
        maximum = minimum;
        minimum = temp;
    }

    for(int i = 0; i <= n-1; i++){
        int difference = arr[i]-k; //value while subtracting k from height
        int sum = arr[i]+k; //value while adding k in height

        if(minimum <= difference || maximum >= sum) //condition to get min and max ovserve yourself
            continue;
        
        if(maximum - difference <= sum-minimum)
            minimum = difference;
        else
            maximum = sum;
    }

    return min(max_diff, maximum-minimum);
}

int main(){
    int arr[] = {1,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<min_height(arr,n,k)<<endl;
    return 0;
}