#include<iostream>
using namespace std;

// Implement min heap

class MinHeap{
    private:
        int * arr;
        int cap;
        int size;

    protected:
        int parent(int i){return (i - 1)/2;} 
        int leftChild(int i){ return 2 * i + 1;}
        int rightChild(int i){return 2 * i + 2;}

    public:
        MinHeap(int cap = 0){
            this->cap = cap;
            this->size = 0;
            this->arr = new int(cap);
        }

        void insert(int data){
            //Check if heap is full
            if(size == cap){
                cout << "Heap overflow" << endl;
                return;
            }
            
            // Insert at the end and check if the inserted is violating the heap structure
            arr[size] = data;
            size++;

            int i = size - 1;
            while(i > 0 && arr[parent(i)] > arr[i]){
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }
        }

        int peek(){
            if(size == 0){
                cout << "Heap Underflow" << endl;
                return -1;
            }
            return arr[0];
        }

        void heapify(int i){
            int l = leftChild(i);
            int r = rightChild(i);
            int smallest = i;

            if(l < size && arr[l] < arr[smallest])
                smallest = l;

            if(r < size && arr[r] < arr[smallest])
                smallest = r;
            
            if(smallest != i){
                swap(arr[smallest], arr[i]);
                heapify(smallest);
            }
        }

        int extractMin(){
            if(size > 0){
                if(size == 1){
                    size--;
                    return arr[0];
                }

                int res = arr[0];
                swap(arr[size-1], arr[0]);
                size--;
                return res;
            }else{
                cout << "Heap empty" << endl;
                return -1;
            }
        }

        int deleteKey(int i){

            if(size == 0){
                cout << "Heap is empty" << endl;
                return -1;
            }
            int res = arr[i];
            // Decrease value of given index so that it cames to the root 
            arr[i] = INT_MIN;
            while(i > 0 && arr[parent(i)] > arr[i]){
                swap(arr[parent(i)], arr[i]);
                i = parent(i);
            }

            // Now remove root to delete the node
            extractMin();
            return res;
        }
};


// Implement Pririty Queue

class PQueue{
    MinHeap h;
    public:
        PQueue(int size){
            MinHeap heap(size);
            this->h = heap;
        }
        void insert(int data){
            h.insert(data);
        }

        int peek(){
            return h.peek();
        }

        int pop(){
            return h.extractMin();
        }
};

int main(){
    PQueue q(5);
    q.insert(39);
    q.insert(33);
    q.insert(31);

    q.pop();

    cout << q.peek() << endl;
    return 0;
}