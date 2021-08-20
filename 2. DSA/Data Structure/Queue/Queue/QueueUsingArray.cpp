// <<<<<<<<<<<<<<<<< Queue Using Class >>>>>>>>>>>>>>>>>

#include <iostream>
using namespace std;

class Queue
{
    int size = 5;
    int front;
    int rear;
    int arr[5];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    //Queue important functions
    void enqueue(int);
    int dequeue();
    void display(void);
    int isEmpty();
    int isFull();
};

void Queue ::enqueue(int data)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
        return;
    }
    else
    {
        this->rear++;
        this->arr[this->rear] = data;
    }
}

int Queue ::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow!!!" << endl;
        return -1;
    }
    else
    {
        return this->arr[++this->front];
    }
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing to show." << endl;
    }
    else
    {
        for (int i = this->front + 1; i <= this->rear; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
}

int Queue::isEmpty()
{
    if (this->front == this->rear)
    {
        return 1;
    }
    else
        return 0;
}

int Queue::isFull()
{
    if (this->rear == this->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    Queue *q = new Queue;
    q->enqueue(121);
    q->enqueue(676);
    q->enqueue(676);
    q->enqueue(676);
    q->enqueue(45);
    int dqdata = q->dequeue();
    q->display();

    return 0;
}

/*

// <<<<<<<<<<<<<<<<< Queue Using Structure >>>>>>>>>>>>>>>>>
#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int r; //rear
    int f; //front
    int *arr;
};

struct Queue *createQueue(int size)
{
    struct Queue *queue = new struct Queue;
    queue->size = size;
    queue->r = -1;
    queue->f = -1;
    queue->arr = new int[queue->size];
    return queue;
}

int isEmpty(struct Queue *q)
{
    if ((q->f == q->r) && (q->r != q->size - 1))
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        cout << "Queue overflow!!!" << endl;
        return;
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct Queue *q)
{
    int reteurnData = -1;
    if (isEmpty(q))
    {
        cout << "Queue Underflow!!! so returing -1" << endl;
        reteurnData = -1;
    }
    else
    {
        q->f++;
        reteurnData = q->arr[q->f];
    }
    return reteurnData;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty no data to display" << endl;
    }
    else
    {
        for (int i = q->f + 1; i <= q->r; i++)
        {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    struct Queue *queue = createQueue(5);
    enqueue(queue, 121);
    enqueue(queue, 343);
    enqueue(queue, 5656);
    enqueue(queue, 5656);
    enqueue(queue, 234);
    // enqueue(queue, 566); //this line will throw Queue overflow as queue is full
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);

    return 0;
}

*/