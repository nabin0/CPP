#include<iostream>
using namespace std;

void swap(int arr[],int a, int b){
      int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}

//Heapify A node 
void max_heapify(int arr[], int i, int n){ //Makes a sub tree heap if it is not. takes i as root of that tree, n is size of the tree
    int left = (i*2)+1; //left child of a node i
    int right = (i*2)+2; // right child of a node i
    int largest= i; //largest var to store idx of largest child if available

    if(left <= n and arr[left] > arr[i]){ //check if left child is greater than root node. i.e if greater than ith node
        largest = left;
    }else{ 
        largest = i;
    }
    if(right <= n && arr[right]  > arr[largest]){ //Now check if the right is greater than root || left child i.e greater than previous largest node
        largest = right;
    }
    if(largest!= i){ //if root is not the largest node then swap it with larger child to make max heap and check same for chid node
        // int temp = arr[largest];
        // arr[largest] = arr[i];
        // arr[i] = temp;
        swap(arr,i,largest);
        max_heapify(arr, largest, n);
    }
}

//Build a  Max Heap

void build_maxHeap(int arr[], int n){  //to create a max heap of given array
for (int i =(n/2) -1; i >= 0; i--)
{
    max_heapify(arr,i,n);
}
}

//Heap sort
void heapSort(int arr[], int n ){

    build_maxHeap(arr,n);

    for (int i = n-1; i >=0; i--)
    {
       swap(arr,0,i);
       max_heapify(arr,0,i-1);
    }
    
}


int main(){
    //Sample arrays
    int arr[] = {3,5,6,7,9,8,23,21,1,2}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    //Invoking heap sort
    heapSort(arr,n);

    //Printing array after Heapify
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<" ";
    }cout<<endl;

    return 0;   
}