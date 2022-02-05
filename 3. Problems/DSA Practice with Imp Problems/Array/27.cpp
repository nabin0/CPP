#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool isSubArrayOfA(int A[], int B[], int na, int nb){

    sort(A,A+na);
    sort(B,B+nb);
    int i  = 0,j = 0;
    int preva = INT_MIN,prevb = INT_MIN;

    while(i <na && j < nb){
        while(preva == A[i]){
            i++;
        }
        while(prevb== B[j]){
            j++;
        }
        if(A[i] == B[j]){
            preva = A[i];
            prevb = B[j];
            i++;j++;
        }else if(A[i] < B[j]){
            preva = A[i];
            i++;
        }
        else{
            return false;
        }
    }

    if(i = na-1 || j == nb-1){
        return true;
    }
    return false;
}


// Iterative method 
bool isSubArray(int A[],int B[], int na , int nb){
    int i, j;
    for ( i = 0; i < nb; i++)
    {
        for ( j = 0; j < na; j++)
        {
            if(B[i] == A[j]){
                break;
            }
        }
        if(j == na){
            return false;
        }
    }
    return true;
}


// Using sorting and binary search method
void quickSort(int *arr, int s, int e);
int binarySearch(int *arr, int n, int key);
bool isSubArrayOf(int *A, int *B, int na, int nb){

    quickSort(A,0,na-1);
    quickSort(B,0,nb-1);

    int i;
    for ( i = 0; i < nb; i++)
    {
        if(binarySearch(A,na,B[i]) == 1){
            continue;
        }else{
            break;
        }
    }
    if(i == nb){
        return true;
    }
    return false;
}

int partitionIdx(int *arr, int s, int e){
    int i = s+1;
    int j = e;
    int pivot=arr[s];

    do{
        while(arr[i] <= pivot){
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
            i++;j--;
        }
    }while(i < j);
    if(i > j){
        swap(arr[s], arr[j]);
    }
    return j+1;
}

void quickSort(int *arr, int s, int e){
    int idx;
    if(s <e){
         idx = partitionIdx(arr, s,e);
        quickSort(arr,s,idx-1);
        quickSort(arr,idx+1,e);
    }
}

int binarySearch(int *arr, int n, int key){
    int s = 0 , e = n-1;
    int mid;
    while(s <= e){
        mid = (s+e)/2;
        if(arr[mid] == key){
            return 1;
        }else if(arr[mid] > key){
            e =mid-1;
        }else if(arr[mid] < key){
            s = mid+1;
        }
    }
    if(s > e){
        return false;
    }
    return true;
} 

int main(){
    int A[] {1,3,4,5,9,12,7,8};
    int B[] {1,3,7,5};
    int na = sizeof(A)/sizeof(A[0]);
    int nb = sizeof(B)/sizeof(B[0]);
    

    // cout<<isSubArrayOfA(A,B,na,nb)<<endl;
    // cout<<isSubArray(A,B,na,nb)<<endl;
    cout<<isSubArrayOf(A,B,na,nb);

    return 0;
}