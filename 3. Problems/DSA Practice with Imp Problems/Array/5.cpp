//Method 1
#include <iostream>
using namespace std;

void rearrangeArray(int arr[], int n)
{
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++) //put all negative elements at the temp array
    {
        if (arr[i] < 0)
        {
            temp[j++] = arr[i];
        }
    }

    //return if the array is full positive or negative
    if (j == n or j == 0)
        return;

    //Put all positive numbers in the left temp array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[j++] = arr[i];
        }
    }

    //put back array elements from temp array to main array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}


void rearrange(int * arr, int n){
    
    for(int i = 0, j = 0; i < n; i++){
        
        if(arr[i] < 0){
            if(i != j){
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

int main()
{
    int arr[] = {-1, 0,2,3,-4};
    int n = sizeof(arr)/4;
    rearrange(arr, n);

    // printing array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// //Method 2
// #include <iostream>
// using namespace std;

// void mvNeg(int arr[], int n)
// {
//     int arrNeg[10] = {0};
//     int arrPos[10] = {0};

//     int j = 0, k = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < 0)
//         {
//             arrNeg[j++] = arr[i];
//         }
//         else if (arr[i] > 0)
//         {
//             arrPos[k++] = arr[i];
//         }
//     }

// //Putting back elements in original array
//     int i = 0;
//     j = 0;
//     while (arrNeg[i] != 0)
//     {
//         arr[j++] = arrNeg[i++];
//     }
//     i = 0;
//     while (arrPos[i] != 0)
//     {
//         arr[j++] = arrPos[i++];
//     }
// }

// int main()
// {
//     int arr[] = {12, 332, 12, -21, -2, -7, 22};
//     mvNeg(arr, 7);
//     for (auto i : arr)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }



//Method 3

#include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n = 5;

//     int arr[n] = {1, -2, -3, 4, -5};
//     int i = 0, j = n - 1;

//     while (i <= j)
//     {
//         if (arr[i] < 0)
//             i++;

//         else if (arr[j] > 0)
//             j--;

//         else if (arr[i] > 0 && arr[j] < 0)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }