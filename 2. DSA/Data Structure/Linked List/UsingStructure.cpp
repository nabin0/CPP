#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

//Traversing and printing array
void traversingList(Node *head)
{
    struct Node *node = head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

//--------------inserton in linkedlist ----------------------

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *node = new struct Node;
    node->data = data;
    node->next = head;
    head = node;

    return head;
}

//Inserts at given index i.e in between two nodes
void insertInBetween(struct Node *head, int index, int data)
{
    struct Node *ptr = head;
    struct Node *node = new struct Node;
    node->data = data;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    node->next = ptr->next;
    ptr->next = node;
}

//insert at the end
void insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = new struct Node;
    struct Node *headPtr = head;
    ptr->data = data;

    while (headPtr->next != NULL)
    {
        headPtr = headPtr->next;
    }
    headPtr->next = ptr;
    ptr->next = NULL;
}

//Insert after a  node
void insertAfterANode(struct Node *ptr, int data)
{
    struct Node *node = new struct Node;
    node->data = data;
    node->next = ptr->next;
    ptr->next = node;
}

//---------------------Deletion functions----------------------
struct Node *deletetionAtHead(struct Node *head)
{
    struct Node *ptr = head;

    head = head->next;
    delete ptr;
    return head;
}

void deletionAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete q;
}

void deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head->next;
    while (ptr->next != NULL)
    {
        head = head->next;
        ptr = ptr->next;
    }
    head->next = NULL;
    delete ptr;
}

void deletionAfterANode(struct Node *ptr)
{
    struct Node *p = new struct Node;
    p = ptr->next;
    ptr->next = p->next;
    delete p;
}

int deletionOfElement(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
        return 0;
    }

    return -1;
}
int main()
{

    //Creating linked list
    struct Node *head = new struct Node;
    struct Node *second = new struct Node;
    struct Node *third = new struct Node;
    struct Node *fourth = new struct Node;

    head->data = 20;
    second->data = 454;
    third->data = 56;
    fourth->data = 11;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    //Invoking iinsertion functions

    // head = insertAtStart(head, 44);
    // insertInBetween(head, 2, 567);
    // insertAtEnd(head,98);
    // insertAfterANode(second, 4645);

    //Invoking deletion functions
    // head = deletetionAtHead(head);
    // deletionAtIndex(head,2);
    // deletionAtEnd(head);
    // deletionAfterANode(second);

    deletionOfElement(head,56);

    traversingList(head);
    return 0;
}

/*

Node * LL::reverse(Node * node){
        if(node == nullptr || node->next == nullptr){
        return node;
    }

    Node *ptr = reverse(node->next);
    node->next->next = node;
    node->next = nullptr;

    return ptr;
}

*/



/* 
# ==================== Using Class ====================
*/

/*

#include<iostream>

struct Node{
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LL{
    Node * head = nullptr;
    Node * reverse(Node *Node);
    public:
    void traversal();
    void insert(int data);
    void deletion(int data);
    void updation(int data, int key);
    Node * search(int key);
    void sort();
    void reverse();
    void reverseIter();
};

void LL::traversal(){
    if(head== nullptr)
        return;
    Node * temp = head;
    while(temp){
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
}

void LL::insert(int data){
    Node * newNode = new Node(data);

    if(head == nullptr){
        head = newNode;
        return;
        }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LL::deletion(int data){
    if(head == nullptr){
        return;
    }

    if(head->next == nullptr){
        if(head->data == data){
            head = nullptr;
            return;
        }else{
            return;
        }
    }

    Node * temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == data){
            break;
        }
        temp= temp->next;
    }
    if(temp->next == nullptr){
        return;
    }
    Node * rm = temp->next;
    temp->next = temp->next->next;
    delete(rm);
    
}

void LL::updation(int data , int key){
    Node * temp = head;
    while(temp){
        if(temp->data == data){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    temp->data = key;
}

Node * LL::search(int key){
    Node * res = nullptr;
    Node * temp = head;
    while(temp){
        if(temp->data == key){
            res = temp;
        }
        temp = temp->next;
    }
    return res;
}

void LL::sort(){
    Node * curr= head;
    Node * nextptr;

    while(curr){
        nextptr = curr->next;
        while(nextptr){
            if(curr->data > nextptr->data){
                int temp = curr->data;
                curr->data = nextptr->data;
                nextptr->data = temp;
            }
            nextptr = nextptr->next;
        }
        curr = curr->next;
    }
}

void LL::reverse(){
    if(head){
        head = reverse(head);
    }
}

Node * LL::reverse(Node * node){
    if(node == nullptr || node->next == nullptr){
        return node;
    }

    Node * res = reverse(node->next);
    node->next->next = node;
    node->next = nullptr;
    return res;
}

void LL::reverseIter(){
    Node * curr = head;
    Node * nextptr;
    Node * prev = nullptr;

    while(curr){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;

    }
    head = prev;
}

int main(){

    LL l;
    l.insert(3);
    l.insert(56);
    l.insert(32);
    l.deletion(13);
    l.insert(21);
    l.updation(32, 12);

    // l.reverse();
    // l.reverseIter();

    l.sort();

    l.traversal();

    Node * founnd = l.search(126);

    if(founnd){
        std::cout << "\nThe item is found " << founnd->data << std::endl;
    }else{
        std::cout << "\nThe item is not found " << std::endl;
    }
    
    return 0;
}

*/