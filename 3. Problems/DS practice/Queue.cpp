#include<iostream>

class Queue{
    int m_front{};
    int m_rear{};
    int m_size {};
    int * arr;

    public:
        Queue(int size = 0): m_size{size}, m_front{-1} , m_rear{-1}{
            arr = new int[size];
        }

        ~Queue(){
            delete[] arr;
        }

        // Queue operations
        void enqueue(int);
        int dequeue();
        int peek(int);
        bool isEmpty();
        bool isFull();
        void traverse();
};

// Member function defintions

void Queue::enqueue(int data){
    if(!isFull()){
        m_rear++;
        arr[m_rear] = data;
    }else{
        std::cout << "The queue is full." << std::endl;
        return;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        std::cout << "The queue is empty " << std::endl;
        return -1;
    }
    m_front++;
    return arr[m_front];
}

bool Queue::isEmpty(){
    return m_front == m_rear;
}

bool Queue::isFull(){
    return m_rear == m_size-1;
}

void Queue::traverse(){
    if(isEmpty()){
        std::cout << "The queue is empty." << std::endl;
        return;
    }
    for (int i = m_front+1; i <= m_rear; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout<<'\n';
}

int main(){

    Queue q{4};

    std::cout << "Enqueue Items " << "\n\n";
    q.enqueue(12);
    q.enqueue(15);
    q.enqueue(56);
    q.enqueue(122);
    // q.enqueue(45); // will print queue full 

    std::cout << "Dequeue items " << std::endl;
    std::cout << "The dequeued item is: " <<q.dequeue() << '\n';
    std::cout << "The dequeued item is: " <<q.dequeue() << '\n';
    std::cout << "The dequeued item is: " <<q.dequeue() << '\n';
    std::cout << "The dequeued item is: " <<q.dequeue() << "\n\n";

    std::cout << "Traversing the queue " << '\n';
    q.traverse();
    
    return 0;
}