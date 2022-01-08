// Min heap 
#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int * y);

class MinHeap{
    int *harr; // Array to store heap items
    int capacity; // Total capacity of the heap
    int heap_size; // Current filled size of heap

    public:
    MinHeap(int); // Constructor for initializing heap data structure

    int parent(int i){ return (i-1)/2;} // returns the parent index of ith index
    int leftChild(int i){ return (i*2)+1;} // returns the left child position of ith item
    int rightChild(int i) {return (i*2)+2;} //returns the right child of the ith item

    void insertKey(int); // Function to insert key
    void deleteKey(int); // delete ith key
    int extractMin(); // Remove min key from heap tree
    void decreaseKey(int, int); // decrease ith key value to another min value
    int getMin(); // Retruns the 0th element of min heap
    void minHeapify(int); // arranges the tree by puttiong ith element at its correct position
};
class MaxHeap{
    int *harr;
    int capacity;
    int heap_size;

    public:
    MaxHeap(int);

    int parent(int i){return (i-1)/2;}
    int leftChild(int i){return i*2+1;}
    int rightChild(int i){return i*2+2;}

    void insertKey(int);
    int extractMax();
    void deleteKey(int);
    int getMax();
    void increseKey(int,int);
    void maxHeapify(int);
};

// Min heap functions
MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    this->harr = new int[capacity];
    this->heap_size = 0;
}
void MinHeap::insertKey(int key){
    // if heap array is full return
    if(heap_size == capacity){
        cout<<"Overflow: cannot insert item in heap tree"<<endl;
        return;
    }
    // If heap array is not full insert item at last index
    heap_size++;
    int i = heap_size-1;
    harr[i] = key;

    // If key at inserted positon violates the rule of heap tree then arrange the tree by reallocating the inserted key at correct position
    while(i > 0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}
void MinHeap::decreaseKey(int i, int newKey){
    harr[i] = newKey;

    while(i >0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}
int MinHeap::extractMin(){
    // If tree is empty
    if(heap_size <= 0){
        cout<<"Underflow: Tree is empty"<<endl;
        return INT_MAX;
    }
    // If tree has only one element return that element
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    // If tree is not empty and it have more than 1 item
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
}
void MinHeap::minHeapify(int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;

    if(l < heap_size && harr[l] < harr[i]){
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest])
    {
        smallest = r;
    }
    if(i != smallest){
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}
int MinHeap::getMin(){
    if(heap_size > 0){
        return harr[0];
    }else{
        cout<<"Heap is empty"<<endl;
        return -1;
    }
}
void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

//Max heap functions
MaxHeap::MaxHeap(int capacity){
    this->capacity = capacity;
    this->harr= new int[capacity];
    this->heap_size = 0;
}
void MaxHeap::insertKey(int key){
    if(heap_size == capacity){
        cout<<"Overflow: cannot insert in tree as tree is full"<<endl;
        return;
    }
    heap_size++;
    int i= heap_size -1;
    harr[i] = key;

    while(i > 0 && harr[parent(i)] < harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i=parent(i);
    }
}
void MaxHeap::increseKey(int i, int newKey){
    harr[i] = newKey;

    while(i > 0 && harr[parent(i)] < harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i=parent(i);
    }
}
int MaxHeap::getMax(){
    if(heap_size > 0){
    return harr[0];
    }else{
        cout<<"Tree is empty"<<endl;
        return INT_MIN;
    }
}
void MaxHeap::maxHeapify(int i){
    int l = 2*i+1;
    int r = 2*i +2;
    int largest = i;
    if(l < heap_size && harr[l] > harr[i]){
        largest = l;
    }
    if(r < heap_size && harr[r] > harr[largest]){
        largest =r;
    }
    if(i != largest){
        swap(&harr[i], &harr[largest]);
        maxHeapify(largest);
    }
}
int MaxHeap::extractMax(){
    if(heap_size <= 0){
        cout<<"Underflow : Heap tree is empty"<<endl;
        return INT_MIN;
    }
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size -1];
    heap_size--;
    maxHeapify(0);
    return root;
}
void MaxHeap::deleteKey(int i){
    increseKey(i, INT_MAX);
    extractMax();
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    cout<<"Max heap: "<<endl;
    MaxHeap h1(5);
    h1.insertKey(23);
    h1.insertKey(3);
    h1.increseKey(1,67);
    h1.deleteKey(0);
    cout<<h1.getMax()<<endl;
    cout<<h1.extractMax()<<endl;
    cout<<h1.getMax()<<endl;

    cout<<"Min heap : "<<endl;
    MinHeap h(5);
    h.insertKey(45);
    h.insertKey(3);
    h.insertKey(32);
    h.deleteKey(1);
    h.decreaseKey(2,1);
    cout<<h.extractMin()<<endl;
    cout<<h.getMin()<<endl;
    
    return 0;
}