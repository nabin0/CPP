#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;

    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

//Comparison function used for sorting array
bool cmp(struct Item a, struct Item b){
    double aratio = (double)a.value/(double)a.weight;
    double bratio = (double)b.value/(double)b.weight;
    return aratio>bratio;
}

//Fractionall knapsack problem
double fractionalKnapsack(int W, Item arr[], int n){
    //Sort array in non-descending order
    sort(arr,arr+n,cmp);

    // for (int i = 0; i < n; i++)//Printing ratio in ascending order
    // {
    //     cout<<(double)arr[i].value/(double)arr[i].weight<<" ";
    // }

    //Variable to For Values and weight while filling
    double currentWeight = 0;
    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if(currentWeight + arr[i].weight <= W){
            currentWeight+=arr[i].weight;
            totalValue += arr[i].value;
        }
        else{
            double leftW = W-currentWeight;
            totalValue += ((double)arr[i].value/(double)arr[i].weight)*leftW;
            break;
        }
    }
    return totalValue;
}


int main(){
    // Item arr[] = {{40, 10}, {50,5}, {120, 15}, {10,40}}; int w = 30; //Answer will be : 210
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; int w = 50; //Answer will be : 240
    double maxVal = fractionalKnapsack(w,arr,3);
    cout<<maxVal<<endl;
    
    return 0;
}
