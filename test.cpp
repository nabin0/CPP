#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

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
    // struct stack s;
    // s.size = 20;
    // s.top = -1;
    // s.arr = new int[20];

    struct stack *s;
    // s->size = 60;
    // s->top = -1;
    // s->arr = new int(67);

    cout << "'testinf'";

    // if(isEmpty(s)==1){
    //     cout<<"stack is empty"<<endl;
    // }
    // else{
    //     cout<<"Stack is not empty"<<endl;
    // }
    // if(isFull(s)){
    //     cout<<"stack is full"<<endl;
    // }
    // else{
    //     cout<<"Stack is not not full"<<endl;
    // }

    return 0;
}