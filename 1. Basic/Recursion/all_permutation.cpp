#include<iostream>
#include<vector>
using namespace std;

// Takes N! * N time complexity and N + N! SC
void recPermute(vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr, int taken[]){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(!taken[i]){
            ds.push_back(arr[i]);
            taken[i] = 1;
            recPermute(ans, ds, arr, taken);
            taken[i] = 0;
            ds.pop_back();
        }
    }

}

// Optimised function for recursive permutation
void recOptmPermute(vector<vector<int>> &ans, vector< int > & arr, int idx){
    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i = idx; i < arr.size(); i++){
        swap(arr[i], arr[idx]);
        recOptmPermute(ans, arr, idx + 1);
        swap(arr[i], arr[idx]);
    }
}

vector<vector<int>> getAllPermutation(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int taken[arr.size()] = {0};
    // recPermute(ans, ds,arr, taken);
    recOptmPermute(ans, arr, 0);
    return ans;
}

void print(const vector<vector<int>> &v){
    for(auto i : v){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main(){

    vector<int> arr {1,2,3};

    vector<vector<int>> ans = getAllPermutation(arr);

    print(ans);
    
    return 0;
}