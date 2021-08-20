#include <iostream>
using namespace std;

//Stack creation and other functions
struct stack
{
    int size;
    int top;
    char *arr;
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

struct stack *createStack(int size)
{
    struct stack *s = new struct stack;
    s->size = size;
    s->top = -1;
    s->arr = new char[s->size];

    return s;
}

void push(struct stack *s, char data)
{
    if (isFull(s))
    {
        cout << "Stack overflow" << endl;
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(struct stack *s)
{
    int temp = s->top;
    if (isEmpty(s))
    {
        cout << "Stack underflow" << endl;
        return '0';
    }
    else
    {
        s->top--;
        return s->arr[temp];
    }
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int isoperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
    {
        return 1;
    }
    return 0;
}

int precidence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infixToPostfix(char *exp)
{
    struct stack *s = new struct stack;
    s->size = 100;
    s->top = -1;
    s->arr = new char[s->size];

    char *postfix = new char[100];
    int p = 0;
    int q = 0;
    while (exp[p] != '\0')
    {
        if (!isoperator(exp[p]))
        {
            postfix[q] = exp[p];
            p++;
            q++;
        }
        else
        {

            if (precidence(exp[p]) > precidence(stackTop(s)))
            {
                push(s, exp[p]);
                p++;
            }
            else
            {
                postfix[q] = pop(s);
                q++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[q] = pop(s);
        q++;
    }
    postfix[q] = '\0';
    
    return postfix;
}

int main()
{
    char infix[] = "a+b/c-a-v";
    cout << infixToPostfix(infix);
    return 0;
}