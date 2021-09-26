#include<iostream>
#include<climits>
using namespace std;

typedef struct item{
    int data;
    int prority;
} it;

it prArr[100]; //Array to store data and priority i.e to store node
int size = -1; //size of empty array

void enqueue(int data, int prority){ //Adds item in the queue
    ::size++;

    prArr[::size].data = data;
    prArr[::size].prority = prority;
}

int peek(){ //Returns index of item with highest priority
    int maxPrority = INT_MIN;
    int idx = -1;

    for (int i = 0; i <= ::size; i++)
    {
        //Check conditioin for same priority iiitems
        if(prArr[i].prority == maxPrority && idx > 0  && prArr[idx].data < prArr[i].data ){
            maxPrority = prArr[i].prority;
            idx = i;
        } else if(maxPrority < prArr[i].prority){
            maxPrority = prArr[i].prority;
            idx = i;
        }
    }
    return idx;
}

void dequeue(){
    int idx = peek(); //Get index of maximum element and shift each after that by one step left

    for (int i = idx; i <= ::size; i++)
    {
        prArr[i] = prArr[i+1];
    }::size--;
}

void displayQueue(){
    cout<<"(Value, Priority)  ";
    for (int i = 0; i <= ::size; i++)
    {
        cout<<"("<<prArr[i].data<<", "<<prArr[i].prority<<"),  ";
    }
    cout<<endl;
}

int main(){
    //Enqueuing elements in the priority queue
    enqueue(12,3);
    enqueue(124,6);
    enqueue(512,2);
    enqueue(2,1);
    enqueue(65,5);
    //Peek
    int idx = peek();
    cout<< "Value at peek Idx is  " << prArr[idx].data <<endl;
    //Dequeue
    dequeue();
    displayQueue();
    return 0;
}