#include<iostream>
#include<cassert>
#include<string.h>


class Stack{
    char m_stack_size{};
    char m_stack_top{};
    char *m_stack_array{};

    public:

        Stack(char size = 0): m_stack_size{size}, m_stack_top{-1}{
            assert(size >= 0);
            m_stack_array = new char[size];
        }

        ~Stack(){
            delete [] m_stack_array;
        }

        // Member function of stack (Stack operations)
        void push(char data);
        char pop();
        char peekTop();
        bool isEmpty();
        bool isFull();
};

void Stack::push(char data){
    if(!isFull()){
        ++m_stack_top;
        m_stack_array[m_stack_top] = data;
    }else{
        std::cout << "Stack Overflow!!!" << std::endl;
    }
}


char Stack::pop(){
    if(isEmpty()){
        std::cout << "Stack Underflow!!!" << std::endl;
    }
    char temp = m_stack_array[m_stack_top];
    --m_stack_top;
    return temp;
}

bool Stack::isEmpty(){
    return m_stack_top == -1;
}

bool Stack::isFull(){
    return m_stack_top == m_stack_size-1;
}

char Stack::peekTop(){
    if(isEmpty()){
        std::cout << "Stack is Empty." << std::endl;
        return ' ';
    }
    return m_stack_array[m_stack_top];
}


// Applicaations of stack
bool isOperator(char ch){ // Check if the given character is a operator or not
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
        return true;
    }
    return false;
}

int precedence(char ch){  // Returns the prcidence of given operator
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '^'){
        return 3;
    }
    return 0;
    
}

char * infixToPostfix(char * infix){

    Stack s(strlen(infix)); // Create a stack
    char * postfix = new char[strlen(infix)]; // Create a char array to store postfix expression
    
    int i = 0; // to track infix
    int j = 0; // To track postfix

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){ // If current char is not operator add to postfix
            postfix[j] = infix[i];
            i++;j++;
        }else{
            if(!s.isEmpty()){ // if stack is not empty check precidence of stack top and current operator
                 if( precedence(infix[i]) > precedence(s.peekTop())){ 
                    s.push(infix[i]);
                    i++;
                }else{
                    postfix[j] = s.pop();
                    j++;
                }
            }else{ // if stack is empty push the current operator to the stack
                s.push(infix[i]);
                i++;
            }
        }
    }

    while(!s.isEmpty()){ // add to left stack items to postfix expression
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '\0'; // Null termintion character

    return postfix;
}

char *reverse(char* exp){
    Stack s(strlen(exp));

    int i = 0;
    while(exp[i] != '\0'){
        s.push(exp[i]);
        i++;
    }

    char * reversed_exp = new char[strlen(exp)];
    i = 0;
    while(!s.isEmpty()){
        reversed_exp[i] = s.pop();
        i++;
    }
    
    return reversed_exp;
}

char * infixToPrefix(char * infix){ // same as infixToPostfix just reverse the expressin before execution and one time after execution
    char * postfix = new char[strlen(infix)];

    infix = reverse(infix);
    postfix = infixToPostfix(infix);
    postfix = reverse(postfix);

    return postfix;
}

// Parenthesis matching
bool match(char ch1, char ch2){
    if(ch1 == '(' && ch2 == ')' || ch1 == '{' && ch2 == '}' || ch1 == '[' && ch2 == ']'){
        return true;
    }
    return false;
}

bool parenthesisMatching(char * exp){
    Stack s(strlen(exp));

    int i = 0;
    while(exp[i] != '\0'){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
            i++;
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(s.isEmpty()){
                return false;
            }else{
                char popped_char = s.pop();
                if(match(popped_char, exp[i] )){
                    i++;
                }else{
                    return false;
                }
            }
        }
        else{
            i++;
        }
    }

    if(s.isEmpty()){
        return true;
    }
    return false;
}

int main(){

    Stack s(4);
    
    s.push('c');
    s.push('a');
    s.push('b');
    s.push('r');
    // s.push('u'); // Will give stack Overflow

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    // s.pop(); // Will give stack underflow

    char exp[] = "a+b*c+d";
    // std::cout << infixToPostfix(exp) << std::endl;
    // std::cout << infixToPrefix(exp) << std::endl;

    char exp1[] = "a(a+{}c)";
    std::cout << std::boolalpha << parenthesisMatching(exp1) << std::endl;
    
    return 0;
}