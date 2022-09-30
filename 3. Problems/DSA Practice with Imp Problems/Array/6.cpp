#include <iostream>
using namespace std;

int *ArrayUnion(int A[], int B[], int n1, int n2)
{
    int *unionArr = new int[n1 + n2];

    int i = 0, j = 0, k = 0;

    while (j < n1 && k < n2)
    {
        if (A[j] > B[k])
        {
            unionArr[i++] = B[k++];
        }
        else if (A[j] < B[k])
        {
            unionArr[i++] = A[j++];
        }
        else
        {
            unionArr[i++] = A[j++];
            k++;
        }
    }

    //leftover elements
    while (j < n1)
    {
        unionArr[i++] = A[j++];
    }
    while (k < n2)
    {
        unionArr[i++] = B[k++];
    }

    for (int val = 0; val < i; val++)
    {
        cout << unionArr[val] << " ";
    }cout<<endl;

    return unionArr;
}

void printIntersection(int A[], int B[], int n1, int n2){
    int i=0,j=0;
    while (i<n1 && j< n2)
    {
        if(A[i] < B[j])
            i++;
        else if(A[i] > B[j])
        j++;
        else{
        cout<<A[i]<<" ";
    i++;j++;
        }
    }
    cout<<endl;
}

int main()
{
    int A[] = {1, 3, 4, 6};
    int B[] = {4, 5, 6, 9};
    ArrayUnion(A, B, 4, 4);
    printIntersection(A,B,4,4);

    return 0;
}