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