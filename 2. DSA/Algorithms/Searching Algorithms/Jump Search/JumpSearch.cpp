#include<iostream>
#include<math.h>
using namespace std;

int jumpSort(int *arr, int n, int key){
    int m = sqrt(n);
    int k = 0;
    // Jump till arr[k*m] is > than key
    while (key >= arr[k*m])
    {
        if(arr[k*m] == key){
            return k*m;
        }
        k++;
    }

    // now use linear search between previous and this point
    for (int i = (k-1)*m; i < k*m; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int JumpSort(int arr[], int n, int key){
    int step = sqrt(n);
    int prev = 0;

    // Jump with sqrt(n) step until greater then the key is found in array
    while(arr[min(step, n)] < key){
        prev = step;
        step += sqrt(n);
        if(prev > n){
            return -1;
        }
    }

    // Applying linear search after finding the range in which key element lies 
    while(arr[prev] < key){
        prev++;
        if(prev == n){
            return -1;
        }
    }
    
   if(arr[prev] == key){
       return prev;
   } 
   return -1;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    cout<<jumpSort(arr,n,2);
    cout<<JumpSort(arr,n,2);
    
    return 0;
}