#include <iostream>
using namespace std;

void printArr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) ///For passes
    {
        for (int j = 0; j < (n - 1 - i); j++) //For comparision and swapping
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp, isSorted = 0;
    for (int i = 0; i < n - 1; i++) ///For passes
    {
        isSorted = 1;
        // cout << "The pass no is : " << i + 1 << endl; //Printing pass number
        for (int j = 0; j < (n - 1 - i); j++) //For comparision and swapping
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {3, 121, 45, 64, 112, 456, 1, 222, 334, 5, 5555, 7777, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size); //before sorting
    bubbleSort(arr, size);
    printArr(arr, size); //After sorting

    /*
    int arrForAdaptive[] = {1,2,3,4,5,6,7,8,9,10,45,7};
    int s = sizeof(arrForAdaptive) / sizeof(arrForAdaptive[0]);
    bubbleSortAdaptive(arrForAdaptive, s);
    printArr(arrForAdaptive, s);
*/
    return 0;
}