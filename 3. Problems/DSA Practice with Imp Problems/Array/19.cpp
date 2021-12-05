#include<iostream>
#include<climits>
using namespace std;

void commonElem(int *A, int *B, int *C, int sa, int sb, int sc){
    int i = 0, j=0, k=0; // for iteration
    int preva,prevb,prevc; // to check if the current element is same as previous element i.e to remove duplicacy
    preva = prevb = prevc = INT_MIN;

    while (i<sa && j < sb && k < sc)
    {

        // move forward if there are duplicate elements  as previous one
        while(preva == A[i] && i < sa)
            i++;
        
        while(prevb == B[j] && j < sb)
            j++;
        
        while(prevc == C[k] && k < sc)
            k++;
        
        if(A[i] == B[j] and B[j] ==C[k]){
            preva = A[i];
            prevb = B[j];
            prevc = C[k];
            cout<<A[i]<<" ";
            i++;j++;k++;
        }
        else if(A[i] < B[j])
            i++;
        
        else if(B[j] < C[k])
            j++;
        else
         k++;
    }
    
}

int main(){
    int A[] = {1,2,2,2,2,2,3,5,7};
    int B[] = {2,5,8,9};
    int C[] = {2,4,5,7,9,20};
    int sA = sizeof(A)/sizeof(A[0]);
    int sB = sizeof(B)/sizeof(B[0]);
    int sC = sizeof(C)/sizeof(C[0]);

    commonElem(A,B,C,sA,sB,sC);
    return 0;
}