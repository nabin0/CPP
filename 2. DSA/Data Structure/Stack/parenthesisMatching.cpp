#include <iostream>
using namespace std;

//forward declaration of stack function
struct stack
{
    int size;
    int top;
    char *arr;
};
struct stack *createStack(int);
void display(struct stack *);
int isEmpty(struct stack *);
int isFull(struct stack *);
char pop(struct stack *);
void push(struct stack *, char);

//Paranthesis matching

int parenthesisMatching(string str)
{
    struct stack *s = createStack(45);
    
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            push(s, str[i]);
            i++;
        }
        else if (str[i] == ')')
        {
            if (!isEmpty(s))
            {
                pop(s);
                i++;
            }
            else
            {
                cout << "Expression is not balanced. Reason : stack underflow" << endl;
                return -1;
            }
        }
        else
        {
            i++;
        }
    }

    if (isEmpty(s))
    {
        cout << "Expression is balanced" << endl;
        return 1;
    }
    else
    {
        cout << "Expression is not balanced. Reason : Stack at termination is not empty" << endl;
    }
    return -1;
}

//Stack creation and other functions

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

int main()
{

    //checking stack functions
    // struct stack *s = createStack(45);
    // push(s, 'a');
    // push(s, 'r');
    // push(s, 'w');
    // pop(s);
    // display(s);

    parenthesisMatching("hf())hoa(khd))");

    return 0;
}