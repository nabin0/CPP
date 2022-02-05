#include<iostream>
#include<climits>
#include<assert.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap{
    int * heap_array{};
    int capacity{};
    int heap_size;

    protected:
    int parent(int i){return (i-1)/2; }
    int left_child(int i) {return (i*2)+1; }
    int right_child(int i) {return (i*2)+2; }

    int extract_min(); // Deletes the min element
    void heapify(int index); 

    public:
    MinHeap(int capacity);
    void insert(int key);
    int remove(int key);
    void decrease_key(int i, int key);
    int get_min();
};

MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    heap_array = new int[capacity];
    heap_size = 0;
}

void MinHeap::insert(int key){
    if(heap_size == capacity){
        std::cout << "Cannot insert. Tree is full." << std::endl;
        return;
    }

    int i = heap_size;
    heap_array[i] = key;
    ++heap_size;

    while(i > 0 && heap_array[parent(i)] > heap_array[i]){
        swap(&heap_array[parent(i)], &heap_array[i]);
        i = parent(i);
    }
}

int MinHeap::remove(int index){
    decrease_key(index, INT_MIN);
    return extract_min();
}

int MinHeap::extract_min(){
    if(heap_size == 0){
        std::cout << "Heap is Empty" << std::endl;
        return INT_MAX;
    }

    if(heap_size == 1){
        --heap_size;
        return heap_array[0];
    }
    
    int res = heap_array[0];
    heap_array[0] = heap_array[heap_size-1];
    --heap_size;
    heapify(0);

    return res;
}

void MinHeap::decrease_key(int index, int key){
    assert(heap_size >= index); // Sanity check

    heap_array[index] = key;

    while(index > 0 && heap_array[parent(index)] > heap_array[index]){
        swap(&heap_array[parent(index)], &heap_array[index]);
        index= parent(index);
    }
}

void MinHeap::heapify(int index){
    int l_child = left_child(index);
    int r_child = right_child(index);
    int smallest = index;

    if(l_child < heap_size && heap_array[l_child] < heap_array[smallest]){
        smallest = l_child;
    }
    if(r_child < heap_size && heap_array[r_child] < heap_array[smallest]){
        smallest = r_child;
    }

    if(smallest != index){
        swap(&heap_array[smallest], &heap_array[index]);
        heapify(smallest);
    }
}


int MinHeap::get_min(){
    if(heap_size == 0){
        std::cout << "Heap is empty." << std::endl;
        return INT_MAX;
    }
    return heap_array[0];
}

int main(){

    MinHeap h(4);

    h.insert(31);
    h.insert(21);
    h.insert(12);
    h.insert(18);

    h.decrease_key(1, 2);

    // h.remove(0);

    std::cout << h.get_min() << " ";
    
    return 0;
}