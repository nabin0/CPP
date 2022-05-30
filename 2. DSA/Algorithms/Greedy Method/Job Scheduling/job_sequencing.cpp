#include<iostream>
#include<algorithm>
using namespace std;

//Structure for probem 
struct Job{
    char id; //Id of job
    int deadline; //Deadline of job
    int profit; //Profit value of the job
};

bool comparison(Job a, Job b){
    return a.profit > b.profit;
}

void print_job_sequence_maxProfit(Job arr[], int n){// n is number of jobs

    //Sorting jobs in descending order according to their profit
    sort(arr,arr+n,comparison);

    int resultIdx[n]; //Array to store index of result value
    bool slot[n] = {false}; //to manage jobs according to deadline 

    for (int i = 0; i < n; i++) //traverse all elements in decreasing profit order
    {
        for (int j = min(n,arr[i].deadline) -1; j > 0; j--) //checking if the slot is free from the last of deadline value or available max time(n)
        {
            if(slot[j] == false){ 
                resultIdx[j] = i; //if slot is availabe put job at that position 
                slot[j] = true;
                break;
            }
        }
        
    }

    //Printing Id's of job in sequence for max profit
    for (int i = 1; i < n; i++)
    {
        cout<<arr[resultIdx[i]].id<<" ";
    }cout<<endl;
    
    
}

int main(){
    Job arr[] = {{'A', 2,40}, {'B', 5, 50},{'C', 1, 90}, {'D', 1, 85}};
    int s = sizeof(arr)/sizeof(arr[0]);
    cout<<s<<endl;
    print_job_sequence_maxProfit(arr,s); //Time to finish all job is s in this casse. s is no of jobs 
    return 0;
}