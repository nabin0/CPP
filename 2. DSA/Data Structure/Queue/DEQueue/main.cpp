#include <iostream>
using namespace std;

class Queue
{
    int size;
    int rear, front;
    int *arr;

public:
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        rear = -1;
        front = -1;
    }
    void insertAtFront(int);
    void insertAtRear(int);
    int deleteAtFront();
    int deleteAtRear();
    bool isEmpty();
    bool isFull();
    int getFront();
    int getRear();
};

void Queue::insertAtFront(int data)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = size - 1;
    else
        front--;
    arr[front] = data;
}

void Queue::insertAtRear(int data)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == size - 1)
        rear = 0;
    else
        rear++;
    arr[rear] = data;
}

int Queue::deleteAtFront()
{
    int data = arr[front];
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
        data - 1;
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;
    }
    return data;
};

int Queue::deleteAtRear()
{
    int data = rear;
    if (isEmpty())
    {
        cout << "Queue underflow!!!" << endl;
        data = -1;
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    return arr[data];
};

int Queue::getFront(){
    if(isEmpty()){
        cout<<"Queue is empty!!!"<<endl;
        return -1;
    }else{
        return arr[front];
    }
}


int Queue::getRear(){
    if(isEmpty()){
        cout<<"Queue is empty!!!"<<endl;
        return -1;
    }else{
        return arr[rear];
    }
}

bool Queue ::isEmpty()
{
    return (front == -1);
}

bool Queue::isFull()
{
    return (rear == (size - 1) && front == 0) || (rear + 1 == front);
}

int main()
{

    Queue qe(3);
    qe.insertAtFront(23);
    qe.insertAtRear(34);
    qe.insertAtFront(76);
    // cout << qe.deleteAtFront() << endl;
    // cout << qe.deleteAtRear() << endl;
    // cout<<qe.deleteAtFront()<<endl;
    cout<<qe.getFront()<<endl;
    cout<<qe.getRear()<<endl;

    if (qe.isEmpty())
    {
        cout << "Empty" << endl;
    }
    if (qe.isFull())
    {
        cout << "full" << endl;
    }
    return 0;
}