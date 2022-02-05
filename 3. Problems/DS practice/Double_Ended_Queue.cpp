#include<iostream>

class Dequeue{
    int size;
    int rear, front;
    int *arr;

    public:
    Dequeue(int size = 0){
        this->size = size;
        this->arr = new int[size];
        this->rear =  this->front = -1;
    }

    // Queuue operations
    void push_back(int data);
    void push_front(int data);
    int pop_back();
    int pop_front();

    bool isEmpty();
    bool isFull();

    int get_front();
    int get_back();
};

// Enqueue operations
void Dequeue::push_front(int data){
    if(isFull()){
        std::cout << "The queue is full." << std::endl;
        return;
    }
    if(front == -1){
        front = rear = 0;
    }else if(front == 0){
        front = size-1;
    }
    else{
        front--;
    }

    arr[front] = data;
}

void Dequeue::push_back(int data){
    if(isFull()){
        std::cout << "The queue is full." << std::endl;
        return;
    }

    if(rear == -1){
        front = rear = 0;
    }else if(rear == size-1){
        rear = 0;
    }
    else{
        rear++;
    }
    arr[rear] = data;
}

// Dequeue Operations
int Dequeue::pop_back(){
    if(isEmpty()){
        std::cout << "Queue is empty " << std::endl;
        return -1;
    }
    int res = arr[rear];
        if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = size-1;
    }else{
        --rear;
    }
    return res;
}

int Dequeue::pop_front(){
    if(isEmpty()){
        std::cout << "Queue is empty " << std::endl;
        return -1;
    }
    int res = arr[front];
    if(front == rear){
        front = rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }else{
        ++front;
    }
    return res;
}

int Dequeue::get_back(){
    if(isEmpty()){
        std::cout << "The Queue is empty!!!" << std::endl;
        return -1;
    }
    return arr[rear];
}

int Dequeue::get_front(){
    if(isEmpty()){
        std::cout << "The Queue is empty!!!" << std::endl;
        return -1;
    }
    return arr[front];
}

bool Dequeue::isEmpty(){
    return front ==-1 && rear==-1;
}

bool Dequeue::isFull(){
    return (front == 0 && rear == size-1 || rear+1 == front);
}

int main(){

    Dequeue d(4);
    d.push_front(12);
    d.push_front(34);
    d.push_front(10);
    d.push_back(20);

    std::cout << "popped: " << d.pop_front() << '\n';
    std::cout << "popped: " << d.pop_front() << '\n';
    std::cout << "popped: " << d.pop_front() << '\n';
    // std::cout << "popped: " << d.pop_front() << '\n';
    // std::cout << "popped: " << d.pop_front() << '\n';
    

    std::cout << "Back " << d.get_back() << '\n';
    std::cout <<"Front " << d.get_front() << '\n';
    
    return 0;
}