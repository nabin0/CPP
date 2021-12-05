#include <iostream>
using namespace std;

void mergeArray(int *A1, int n1, int *A2, int n2)
{
    // To  get the solution we first have to sort first array A1 
    // then secong arraay willl contain left elements and after sorting that we will get solution
    int lastElem;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (A1[i] <= A2[j]) // if first array ith elem is smaller than second arrays jth elem increasei 
        {
            i++;
        }
        else 
        {
            lastElem = A1[n1 - 1];
            for (int k = n1 - 1; k > i; k--) // making space to enter jth element in its correct position in first array
            {
                A1[k] = A1[k - 1];
            }
            A1[i] = A2[j]; 
            i++;

            int temp = j;
            while (A2[temp] < lastElem) // finding correct positin for the last element 
            {
                temp++;
            }

            for (int k = j; k < temp; k++) // making position for ith element 
            {
                A2[k] = A2[k + 1];
            }
            A2[temp - 1] = lastElem;
        }
    }

    // Priting arrays
    cout << "A1: ";
    for (int i = 0; i < n1; i++)
    {
        cout << A1[i] << " ";
    }
    cout << endl;

    cout << "A2: ";
    for (int i = 0; i < n2; i++)
    {
        cout << A2[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A1[] = {1, 3, 4, 5, 7, 8};
    int n1 = sizeof(A1) / sizeof(A1[0]);
    int A2[] = {2, 3, 6, 7, 9, 10};
    int n2 = sizeof(A2) / sizeof(A2[0]);

    mergeArray(A1, n1, A2, n2);

    return 0;
}