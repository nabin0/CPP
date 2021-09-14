#include<iostream>
using namespace std;

void reverse(int arr[], int n){
    int i = 0, j = n-1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr,n);
    reverse(arr, n);
    printArr(arr, n);

    return 0;
}