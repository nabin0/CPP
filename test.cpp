#include<iostream>
#include<vector>
using namespace std;

void heapify(int arr[],int i, int n){
    int left = (i*2) +1;
    int right = (i*2) + 2;

    int min  = i;
    if(left < n && arr[left] < arr[min])
        min = left;
    if(right < n && arr[right] < arr[min])
        min = right;
    
    if(min != i){
        swap(arr[i], arr[min]);
        heapify(arr,min,n);
    }
}

void build_heapify(int *arr, int n){
    for(int i = (n/2)-1; i >=0; i--){
        heapify(arr,i,n);
    }
}

int main(){
    int arr[] = {3, 4, 2, 5, 6, 1, 9}; //Correct answer: 1 4 2 5 6 3 9
    int n = sizeof(arr) / sizeof(arr[0]);
    build_heapify(arr,n);

    for(int i = 0; i < n ; i++)
        cout << arr[i] << ' ';    
    return 0;
}