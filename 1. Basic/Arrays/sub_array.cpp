#include<iostream>
#include<vector>
using namespace std;


void printArr(vector<int> v){
    for (auto &&i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void subArr(const vector<int> &v, vector<int> &ans, int pos){
    if(pos == v.size()){
        if(ans.size() > 0)
            printArr(ans);
        return;
    }

    int val = v[pos];
    if(pos == 0 || v[pos - 1] == ans[ans.size()-1] || ans.size() == 0){
        ans.push_back(val);
        subArr(v, ans, pos + 1);
        ans.pop_back();
    }
    subArr(v, ans, pos + 1);
}

int main(){
    vector<int> arr = {1,3,5,4};
    vector<int> ans;
    subArr(arr,ans,0);
    return 0;
}