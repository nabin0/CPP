#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;


// Solution time complexity is nlogn as we are  sorting array
int coinsecutiveSubSequence(int *arr , int n){
    int res = 0, count = 0; // variables for final result ans intermediate results
    sort(arr, arr+n); // Sort array in ascending orders
    vector<int> v; // Vector to store value and removing duplicates 
    v.push_back(arr[0]);

    for (int i = 1; i < n; i++) // Push values one by one ignore duplicates
    {
        if(arr[i] == arr[i-1]){
            continue;
        }
        v.push_back(arr[i]);
    }

    // check how many items are creating coinsecutive sequence i.e differ by same value with each other
    for (int i = 0; i < v.size(); i++)
    {
        if(i > 0 && v[i] == v[i-1]+1){
            count++;
        }else{
            count = 1;
        }
        res = max(res,count);
    }
    return res;
}

// solution in linear time complexity O(n)
int countcoinsecutiveSequence(int *arr, int n){
    int count = 0; // count the number of coinsecutive items
    unordered_set<int> s; // to store the array items all operation can be performed in average O(1)
    for (int i = 0; i < n; i++) // Insert all items in unsorted_set 
    {
        s.insert(arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(s.find(arr[i]-1) == s.end()){ // Check if the item is first element of the sequence or not
            int j = arr[i];

            while(s.find(j) != s.end()){ // it it is the first itemthen check how many items are forming the coinsecutive sequence
                j++;
            }
            count = max(count,j-arr[i]); // Here j is value of last item of coinsecutive sequence so sub arr[i] to get sequence length
        }
    }
    return count;
}

int main(){
    int arr[] = {1,5,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<coinsecutiveSubSequence(arr, n)<<endl;
    cout<<countcoinsecutiveSequence(arr,n)<<endl;
    return 0;
}