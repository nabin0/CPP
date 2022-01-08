#include <iostream>
#include <climits>
using namespace std;

//Bruteforce mthod
int max_sum_contiguous_subarray(int arr[], int n)
{

    int max_sum_till = 0;
    int temp_sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            temp_sum = 0;
            for (int k = i; k <= j; k++)
            {
                temp_sum += arr[k];
                cout << arr[k] << " ";
            }
            cout << "  : and sum of this subarr is: ";
            cout << temp_sum << endl;
            if (max_sum_till < temp_sum)
            {
                max_sum_till = temp_sum;
            }
        }
    }

    return max_sum_till;
}

//Kadanes algorithm

int kdanes_algo_for_max_subarr_sum(int arr[], int n ){
    int max_sum_till = INT_MIN;
    int tempsum = 0;

    for (int i = 0; i < n; i++)
    {
        tempsum+=arr[i];
        if(tempsum < 0){
            tempsum = 0;
        }
        max_sum_till = max(max_sum_till, tempsum);
    }

    return max_sum_till;
    
}

int main()
{
    int arr[] = {12, 1, 3, -4, 5, -11, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << max_sum_contiguous_subarray(arr, n) << endl;
    cout<<kdanes_algo_for_max_subarr_sum(arr,n)<<endl;
    return 0;
}


