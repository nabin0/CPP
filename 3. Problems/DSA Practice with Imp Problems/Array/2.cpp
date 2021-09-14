#include<iostream>
#include<climits>
using namespace std;

void find_minMax(int arr[], int n ){
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if(min > arr[i]){
            min = arr[i];
        }
        if(max < arr[i]){
            max = arr[i];
        }
    }
    cout<<"Min Value : "<< min<<"\nMax Value: "<<max<<endl;
    
}

int main(){
    int arr[] = {2,54,76,88,23,643,98,1,45};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_minMax(arr,n);
    return 0;
}