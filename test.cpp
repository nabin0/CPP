#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr, int size){
    for(int i = 1; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void countSort(int *arr, int size){
    int count[100]{0};

    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    int j =0;
    for(int i = 0; i < 100; i++){
        while(count[i]--){
            arr[j++] = i;
        }
    }
}

void selectionSort(int *arr, int size){
    for(int i = 0; i < size-1; i++){
        int minidx = i;
        for(int j = i+1; j < size; j++){
            if(arr[minidx] > arr[j]){
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
}

void insertionsort(int *arr, int size){
    for(int i = 1; i< size; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int partition(int *arr, int start, int end){
    int pivot = start;
    start++;
    while(start < end){
        while(arr[start] <= arr[pivot]) start++;
        while(arr[end] > arr[pivot]) end--;
        if(start < end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[end], arr[pivot]);
    return end;
}

void quicksort(int *arr, int start,int end){
    if(start < end){
        int pidx = partition(arr, start, end);
        quicksort(arr, start, pidx-1);
        quicksort(arr, pidx+1, end);
    }
}

void merge(int *arr, int start,int mid, int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    int a1[n1];
    int a2[n2];

    for(int i = 0; i < n1; i++)
        a1[i] = arr[i+start];
    
    for(int i = 0; i < n2; i++)
        a2[i] = arr[i+mid+1];
    
    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2){
        if(a1[i] < a2[j])
            arr[k++] = a1[i++];
        else arr[k++] = a2[j++];
    }
    
    while(i < n1)
        arr[k++] = a1[i++];

    while(j < n2)
        arr[k++] = a2[j++];
        
}

void mergesort(int *arr, int start, int end){
    int mid;
    if(start < end){
        mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] {4, 1, 6, 8, 25,78,34,23,12,12,34,4,3,6,311,65, 9};
    int size = sizeof(arr)/4;

    // bubblesort(arr, size);
    // countSort(arr, size);
    // selectionSort(arr, size);
    // insertionsort(arr, size);
    // quicksort(arr, 0, size-1);
    mergesort(arr, 0, size-1);

    //Print sorted array
    for(int i : arr)
        cout << i << ' ';
    return 0;
}
