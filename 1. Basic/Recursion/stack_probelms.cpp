#include<iostream>
#include<stack>
using namespace std;


void insert(stack<int> &st, int val){
    if(st.empty() || st.top() <= val){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insert(st, val);
    st.push(temp);
}

// Problem : sort a stack
void sort(stack<int> &st){
    if(st.size() == 1){
        return;
    }

    int val = st.top();
    st.pop();
    sort(st);
    insert(st, val);
}

//Problem : Delete Kth element from stack
void del(stack<int> &st, int k){
    if(k == 1){
        st.pop();
        return;
    }
 
    int temp = st.top();
    st.pop();
    del(st, k-1);
    st.push(temp);
}



int main(){
    stack<int> st;
    st.push(12);
    st.push(5);
    st.push(7);
    st.push(1);

    // sort(st);


    // del(st,4);

    

    while (!st.empty())
    {
        cout << st.top()<< ' ';
        st.pop();
    }
    

    return 0;
}