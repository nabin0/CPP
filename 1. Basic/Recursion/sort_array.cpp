#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int temp);

void sort(vector<int> &v){
    if(v.size() == 1){
        return;
    }

    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);

    insert(v, temp);    
}


void insert(vector<int> &v, int temp){
    if(v.size() == 0 || v[v.size()-1] <= temp){
        v.push_back(temp);
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
}

int main(){
    vector<int> arr = {1,5,2,-7,3};
    sort(arr);

    for(int i:arr){
        cout << i << ' ';
    }
    return 0;
}