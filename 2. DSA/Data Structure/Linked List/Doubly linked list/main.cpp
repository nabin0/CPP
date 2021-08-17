#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
//creation of linked list
struct node *createLList(int data)
{
    struct node *head = new struct node;
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

//------insertions------
struct node *insertAtBegining(struct node *head, int data)
{
    struct node *ptr = new struct node;
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    head->prev = ptr;
    head = ptr;
    return head;
}

void insertAtEnd(struct node *head, int data)
{
    struct node *ptr = new struct node;
    struct node *q = head;
    ptr->data = data;
    ptr->next = NULL;

    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr->prev = q;
}

//------Deletion at LL ---------

struct node *deletionAtBeginning(struct node *head)
{
    struct node *ptr = head;
    head = ptr->next;
    head->prev = NULL;
    delete ptr;
    return head;
}

void deletionAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    delete q;
}

int main()
{

    /*
    //Creating linked list nodes manulally
    struct node *head = new struct node;
    struct node *second = new struct node;
    struct node *third = new struct node;
    struct node *fourth = new struct node;

    head->data = 45;
    head->prev = NULL;
    head->next = second;

    second->data = 55;
    second->prev = head;
    second->next = third;

    third->data = 78;
    third->prev = second;
    third->next = fourth;

    fourth->data = 98;
    fourth->prev = third;
    fourth->next = NULL;

*/

    struct node *head = new struct node;
    head = createLList(67);

    //Insertion
    head = insertAtBegining(head, 456);
    insertAtEnd(head, 656);

    //Deletion
    head = deletionAtBeginning(head);
    deletionAtEnd(head);
    display(head);

    return 0;
}