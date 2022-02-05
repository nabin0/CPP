#include <iostream>
using namespace std;


// Function to right rotate array
void rightRotate(int arr[], int s, int e)
{
    int temp = arr[e];
    for (int i = e; i > s; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[s] = temp;
}

void rearrangeArray(int *arr, int n)
{
    int wrongPlacedIdx = -1; // The wrong place index is stored in this variable i.e the value index that is violation the alternating squence
    
    for (int i = 0; i < n; i++) // Iterate all elements and check if it is in correct place or not
    {
        if (wrongPlacedIdx >= 0) // if it is in worng place 
        {
            if (arr[i] >= 0 && arr[wrongPlacedIdx] < 0 || arr[i] < 0 && arr[wrongPlacedIdx] >= 0) // Fing the first opposite sign value which can be put in the wrong index to maintain  the sequence
            {
                rightRotate(arr, wrongPlacedIdx, i); // when the opposite sign value item is found rotate array to right from wrong index to that opposite isgn item to maintain the squeence of items of aray
                
                if (i - wrongPlacedIdx >= 2) // if this condition meets it means the  wrongindex +2 value is the another wrong value in array
                {
                    wrongPlacedIdx = wrongPlacedIdx + 2;
                }
                else // otherwise place wrongindex to -1 and check if the ith item is in correct position or not
                {
                    wrongPlacedIdx = -1;
                }
            }
        }else{ // check if the current item is in correct place or not if it is in worng place store its index into wrongIndex var
            if(arr[i] < 0 && i%2 == 1 || arr[i] >= 0 and i %2 ==0){
                wrongPlacedIdx = i;
            }
        }
    }
}

int main()
{
    int arr[] = {-2,2,3,-4,-5,-6,6,7,-8,1,3,4,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}