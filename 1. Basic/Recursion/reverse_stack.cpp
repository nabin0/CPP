#include<bits/stdc++.h>
using namespace std;


void insert(stack<int>&st, int val){
    if(st.size() == 0){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insert(st, val);
    st.push(temp);
}

void reverse(stack<int> &st){
    if(st.size() == 0){
        return;
    }

    int val = st.top();
    st.pop();
    reverse(st);

    insert(st, val);
}

int main(){
    stack<int> st;
    st.push(12);
    st.push(34);
    st.push(67);
    st.push(98);

    reverse(st);

    while(!st.empty()){
        cout << st.top()  << ' ';
        st.pop();
    }
    return 0;
}