#include<iostream>
#include<climits>
using namespace std;

void commonElements(int *a, int *b, int *c, int na, int nb, int nc){
    int i = 0, j=0, k=0;
    int preva,prevb,prevc; 
     preva=prevb=prevc =INT_MIN;
    
    while(i < na && j < nb && k < nc)
    {
        while(i < na && a[i] == preva)
            i++;
        while(j < nb && b[j] == prevb)
            j++;
        while(k < nc && c[k] == prevc)
            k++;

        if(a[i] == b[j] && b[j] == c[k]){  
            preva = a[i];
            prevb = b[j];
            prevc = c[k];
            cout<<a[i]<<" ";
            i++;j++;k++;
        }else if(a[i]< b[j]){
            i++;
        }else if(b[j] < c[k]){
            j++;
        }else{
            k++;
        }
    }
}

int main(){
    int A[] = {1,2,2,2,2,2,3,5,7};
    int B[] = {2,5,8,9};
    int C[] = {2,4,5,7,9,20};
    int sA = sizeof(A)/sizeof(A[0]);
    int sB = sizeof(B)/sizeof(B[0]);
    int sC = sizeof(C)/sizeof(C[0]);
    commonElements(A,B,C,sA,sB,sC);
    return 0;
}