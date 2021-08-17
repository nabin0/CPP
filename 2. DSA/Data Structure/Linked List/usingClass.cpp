#include <iostream>
using namespace std;

//Creating Node Class
class Node
{
public:
    int data;
    Node *next;
};

//Linked list class with useful functions

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    ~LinkedList(){};
    void addNode(int);
    void deleteNode(); //DEletes last node
    void display();
};

//Add new node to the last of the l list
void LinkedList ::addNode(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *tempPtr = head;
        while (tempPtr->next != NULL)
        {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = newnode;
    }
}

//DEletes last node

void LinkedList::deleteNode()
{
    if (head == NULL)
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        Node *p = head;
        Node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        delete q;
    }
}

//Taversing and displaying values
void LinkedList::display()
{
    if (head == NULL)
    {
        cout << "The linked list is empty.\n";
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

main()
{
    LinkedList *lst = new LinkedList; //Object created dynamically in heap memory

    lst->addNode(100);
    lst->addNode(455);
    lst->addNode(233);
    lst->display();
    lst->deleteNode(); //will delete 233
    lst->addNode(9889);
    lst->addNode(565);
    lst->display();

    return 0;
}