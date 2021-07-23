#include<iostream>
using namespace std;

// Binary Search Algo
int binarySearch(int arr[], int n, int key){
    int s = 0; //Start pointer of array
    int e = n-1; //End pointer of array

    while(s <= e){
        int mid = (s +e) /2;

        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }

    return -1;
}


int main(){
    cout << "Enter the size of array." << endl;
    int n;
    cin >> n;

    int arr[n];
    cout<<"Enter the elements of array. Must be in sorted order."<<endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter the element you want search."<<endl;
    int key;
    cin >> key;

    cout << "The entered element is found at index: " << binarySearch(arr, n, key);
    return 0;
}