#include <iostream>
using namespace std;
struct Queue
{
    int size;
    int rear;
    int front;
    int *arr;
};

struct Queue *createQueue(int size)
{
    struct Queue *queue = new struct Queue;
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = new int[queue->size];
    return queue;
}

int isEmpty(struct Queue *q)
{
    if (q->front == q->rear)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *q)
{
    if ((q->rear + 1 % q->size) == q->front)
    {
        return 1;
    }
    else
        return 0;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Nothing to display!!!" << endl;
        return;
    }
    else
    {
        for (int i = q->front+1; i < (q->rear + 1 % q->size); i++)
        {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

void enqueue(struct Queue *q, int data){
    if(isFull(q)){
        cout<<"Queue overflow"<<endl;
        return;
    }else{
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        cout<<"Queue underflow"<<endl;
        return -1;
    }else{
        q->front++;
        return q->arr[q->front];
    }
}

int main()
{
    struct Queue * q = createQueue(3);
    enqueue(q,121);
    enqueue(q,3);
    enqueue(q,12451);
    dequeue(q);
    enqueue(q,76);
    dequeue(q);
    display(q);

    return 0;
}