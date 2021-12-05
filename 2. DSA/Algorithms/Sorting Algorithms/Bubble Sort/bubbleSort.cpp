#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    // Logic for bubble sort
    int counter = 0;
    while (counter < n)
    {
        for (int i = 0; i < n-counter; i++)
        {
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        }
        counter++;
    }
    
    // Printing sorted array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
int arr[] = {2,7,3,5};
int n  = 4;

bubbleSort(arr,n);
return 0;
}