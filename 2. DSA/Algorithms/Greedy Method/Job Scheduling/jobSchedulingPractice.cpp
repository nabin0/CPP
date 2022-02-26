#include<iostream>
#include<algorithm>

struct Job{
    int profit, deadline;

    Job(int p, int t){
        profit = p;
        deadline = t;
    }
};

int cmp(Job a, Job b){
    return a.profit > b.profit;
}

int jobScheduling(Job * arr, int n){ // returns maximum profit
    int takenjob[n]{};

    std::sort(arr,arr+n, cmp);

    int i = 0;
    while(true){
        if(i == n){
            break;
        }
        if(takenjob[arr[i].deadline] == 0){
            takenjob[arr[i].deadline] = arr[i].profit;
            i++;
        }else{
            int j = arr[i].deadline-1;
            while(j > 0){
                if(takenjob[j] == 0){
                    takenjob[j] = arr[i].profit;
                    i++;
                    break;
                }else{
                    j--;
                }
            }
            i++;
        }
    }

    int res = 0;
    for(int i =0; i < n; i++){
        res+=takenjob[i];
    }
    return res;
}

int main(){
    Job j[]{{100,2},{20,1},{200,1},{120,2}};
    int n = sizeof(j)/sizeof(j[0]);
    std::cout << jobScheduling(j,n);
    return 0;
}