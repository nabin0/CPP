#include<iostream>
#include<algorithm>

struct Item{
    int value,weight;
    
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(Item a, Item b){
    double ra = (double)a.value/a.weight;
    double rb = (double)b.value/b.weight;
    return ra > rb;
}

double f_knapsack(Item *arr, int n,int w){
    if(n==0)return 0;
    if(n==1) return arr[0].value;

    std::sort(arr, arr+n, cmp);// Sorting the array descending order according to val by weight ratio

    double totalVal = 0; // Value of weight inserted till now
    int weight_left = w; // Weight left to be filled

    int i;
    for(i = 0; i < n; i++){
        if(weight_left < arr[i].weight){
            break;
        }
        totalVal += arr[i].value;
        weight_left -= arr[i].weight;
    }

    // Adding the left fraction of weight 
    totalVal += ((double)(arr[i].value)/arr[i].weight) * weight_left;

    return totalVal;
}

int main(){
    Item arr[] { { 60, 10 }, { 120, 40 }, { 100, 20 } }; int w = 50; 
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << f_knapsack(arr,n,w);
    return 0;
}