#include <iostream>
using namespace std;
int isEmpty(struct stack *);
int isFull(struct stack *);

struct stack
{
    int size;
    int top;
    int *arr;
};

void push(struct stack *s, int value)
{
    if (isFull(s))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    int ptr = s->top;
    if (isEmpty(s))
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        s->top--;
        return s->arr[ptr];
    }
}

//Peek element at given position
int peek(struct stack *s, int pos)
{
    if (s->top - pos + 1 == 0)
    {
        return -1;
    }
    return s->arr[s->top - pos + 1];
}

//stack top returns the top element of the stack
int stackTop(struct stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s->arr[s->top];
}

//Stack bottom returns bottommost element of stack
int stackBottom(struct stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s->arr[0];
}

//Traverse stack
void display(struct stack *s)
{
    if (s->top == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        cout << s->arr[i] << " ";
    }
    cout << endl;
}

//Functions to check if the stack is empty or full
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == (s->size - 1))
    {
        return 1;
    }
    return 0;
}

int main()
{
    //statcally declarng obj of a structure
    // struct stack s;
    // s.size = 20;
    // s.top = -1;
    // s.arr = new int[20];

    //dynamically allocating stack obj
    struct stack *s = new struct stack;
    s->size = 60;
    s->top = -1;
    s->arr = new int(s->size);

    //Pushing items in the stack
    push(s, 44);
    push(s, 55);
    push(s, 32);
    push(s, 24);
    push(s, 98);
    cout << "Stack after pushing elements: " << endl;
    display(s);

    //Poping elements from the stack
    int val = pop(s);
    cout << "The poped item is : " << val << endl;
    val = pop(s);
    cout << "The poped item is : " << val << endl;
    val = pop(s);
    cout << "The poped item is : " << val << endl;

    cout << "Stack after poping elements : " << endl;
    display(s);

cout<<"Peeking"<<endl;
    val = peek(s, 2);
    cout << val << endl;

    val = stackTop(s);
    cout << val << endl;

    val = stackBottom(s);
    cout << val << endl;

    //----------Check if the stack is empty or full
    if (isEmpty(s) == 1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    if (isFull(s))
    {
        cout << "stack is full" << endl;
    }
    else
    {
        cout << "Stack is not not full" << endl;
    }

    return 0;
}