#include<iostream>
#include<unordered_set>
using namespace std;

void subArraySumZero(int *arr, int n){
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cont = 0;
            for (int k = i; k <= j; k++)
            {
                cont+=arr[k];
            }
            if(cont == 0){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}

bool subArrrayExist(int *arr, int n){
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(sum == 0 || (s.find(sum) != s.end())){
            return true;
        }
        s.insert(sum);
    }
    return false;
}

int main(){

    int arr[] = {2,1,4,-2,1,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // subArraySumZero(arr,n);
    cout<<subArrrayExist(arr,n);

    return 0;
}