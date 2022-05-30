#include<iostream>
using namespace std;

// Create LL

struct Node
{
    int data;
    Node * next;

    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LL{
    private:
        Node * head;
    
    public:
        LL(){
            head = nullptr;
        }

        void add_node(int data){
            Node * newNode = new Node(data);

            if(head == nullptr){
                head = newNode;
                return;
            }

            Node * temp = head;
            while(temp->next){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        Node * remove_node(){
            if(head == nullptr){
                cout << "List is empty " << endl;
               return head; 
            } 

            Node * res;
            if(head->next == nullptr){
                res = head;
                head = nullptr;
                return res;
            }

            Node * temp = head;
            while(temp->next->next){
                temp = temp->next;
            }

            res = temp->next;
            temp->next = nullptr;
            return res;
        }
        
        Node * remove_node(int index){
            if(head == nullptr){
                cout << "List is empty " << endl;
               return head; 
            } 

            Node * res;
            if(index == 0){
                res = head;
                this->head = head->next;
                return res;
            }

            int i = 1;
            Node * temp = head;
            while(i < index){
                temp = temp->next;
            }
            res = temp->next;

            temp->next = temp->next->next;
            return res;
        }

        void traverse(){
            Node*temp = head;

            while (temp)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }cout << endl;
            
        }
};


// Implenent Queue using Linked List

struct Qnode{
    int data;
    Qnode *next;

    Qnode(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
    Qnode * front;
    Qnode * rear;

    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
        }

        void push(int data){
            Qnode * newNode = new Qnode(data);

            if(front == nullptr && rear == nullptr){
                rear = newNode;
                front = newNode;
                return;
            }

            rear->next = newNode;
            rear = rear->next;
        }

        Qnode * pop(){
            Qnode * res;

            if(!isempty()){
                res = front;
                front = front->next;
                return res;
            }else{
                cout << "Queue is empty" << endl;
                return nullptr;
            }
        }

        void traverse(){
            Qnode * temp = front;

            while(temp){
                cout << temp->data << ' ';
                temp = temp->next;
            }cout << endl;
        }

        bool isempty(){
            return front ==nullptr;
        }
};



int main(){

    Queue q;
    q.push(12);
    q.push(23);
    q.push(43);

    q.pop();
    q.pop();
    q.pop();

    q.traverse();

    
    return 0;
}