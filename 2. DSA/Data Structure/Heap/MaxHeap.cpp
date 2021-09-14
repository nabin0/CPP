#include<iostream>
using namespace std;


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
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
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


int main(){
    //Sample arrays
    // int arr[] = {4,7,8,3,2,6,5}; //Correct answer: {8,7,6,3,2,4,5}
    int arr[] = {3,5,6,7,9,8}; //Correct Answer: {9,7,8,3,5,6}
    int n = sizeof(arr)/sizeof(arr[0]);

    //Invoking build heap
    build_maxHeap(arr,n);

    //Printing array after Heapify
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<" ";
    }cout<<endl;

    return 0;   
}