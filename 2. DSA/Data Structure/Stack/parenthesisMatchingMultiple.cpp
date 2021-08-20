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

int match(char a, char b)
{
    if ((a == '(' and b == ')') or (a == '{' and b == '}') or (a == '[' and b == ']'))
    {
        return 1;
    }
    return 0;
}

//--------------parenthesis matching---------
int parenthesisMatching(char *exp)
{
    struct stack *s = new struct stack;
    s = createStack(100);
    char poppeditm;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' or exp[i] == '{' or exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' or exp[i] == '}' or exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            poppeditm = pop(s);
            if (!match(poppeditm, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(s))
    {
        cout<<"Parenthesis is matched"<<endl;
        return 1;
    }
    else
        cout<<"Parenthesis is  not matched"<<endl;
    {
        return 0;
    }
}



int main()
{
    char arr[] = "h{[j]}(((())))d"; //answer will be true
    int result = parenthesisMatching(arr);
    cout << boolalpha << result << endl;

    return 0;
}