#include<iostream>
#include<vector>
using namespace std;

void print(const vector<int> &v){
    for(int i : v)
        cout << i << ' ';
    cout << '\n' ;
}

void sseq(int *arr, int n, int idx, vector<int> &ans){
    if(idx == n){
        print(ans);
        return;
    }

    ans.push_back(arr[idx]);
    sseq(arr, n, idx + 1, ans); // Considering the current element
    ans.pop_back(); // Back tarcking step

    sseq(arr, n, idx + 1, ans); // Not considering the current element
}

int main(){
    int arr[] {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int > v;
    sseq(arr, n , 0, v);
    return 0;
}