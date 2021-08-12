#include <iostream>
#include <climits>
using namespace std;

//Functoion to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Find maximum in the array
int maximum(int arr[], int n)
{
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxm = max(arr[i], maxm);
    }
    return maxm;
}

//count sort algoriithm

void countSort(int *arr, int n)
{
    int maxm = maximum(arr, n);

    //Declaring and initialization temperory array to store repetation of elements in corresponding index

    // int *tempArr = new int[maxm + 1];
    int tempArr[maxm];
    for (int i = 0; i < maxm + 1; i++)
    {
        tempArr[i] = 0;
    }

    //Storing repeatition in temparr
    for (int i = 0; i < n; i++)
    {
        tempArr[arr[i]]++;
    }

    //Initialisation pointer for loop
    int i = 0;
    int j = 0;

    //Now putting elements in order in final array
    while (i <= maxm)
    {
        if (tempArr[i] > 0)
        {
            arr[j] = i;
            j++;
            tempArr[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {12, 34, 23, 22, 56, 12, 6, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    countSort(arr, size);  //Invoing countSort
    printArray(arr, size); //Printing array after sorting

    return 0;
}