#include<iostream>

struct Node{
    int m_data{};
    Node * next_node{};
};

class LinkedList{
    Node * head;

    public:
    LinkedList(){
        head = nullptr;
    }

    ~LinkedList(){
        Node *current = head;
        while(current != nullptr){
            Node * next = current->next_node;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Linked list operations
    void traversal();
    void insertion(int value); // INsert at end
    void insertion(int index, int value); // Insert at given index
    int deletion(); // Delete at end
    int deletion(int index);
    int search(int value);
    void updation(int index, int new_value);
};

void LinkedList::traversal(){
    if(head == nullptr){
        std::cout << "Linked list is empty" << std::endl;
        return;
    }

    Node *temp = head;
    while(temp!=nullptr){
        std::cout << temp->m_data << " ";
        temp = temp->next_node;
    }
    std::cout << std::endl;
}

void LinkedList::insertion(int value){
    // Creating the new node
    Node * new_node = new Node;
    new_node->m_data = value;
    new_node->next_node = nullptr;

    if(head == nullptr){
        head = new_node;
    }else{
        Node * temp = head;
        while(temp->next_node != nullptr){
            temp = temp->next_node;
        }
        temp->next_node = new_node;
    }
}

void LinkedList::insertion(int index, int value){
    // Create a new node
    Node * new_node = new Node;
    new_node->m_data = value;
    new_node->next_node = nullptr;

    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next_node;
    }
    temp->next_node = new_node;
}

int LinkedList::deletion(){
    if(head == nullptr){ // if it is already empty
        std::cout << "Linked List is empty!!" << std::endl;
        return -1;
    }
    
    if(head->next_node == nullptr){ // If there is only one node left
        int return_data = head->m_data;
        head = nullptr;
        return return_data;
    }

    Node * temp = head;
    while(head->next_node->next_node != nullptr){
        head = head->next_node;
    }
    int return_data = temp->next_node->m_data;
    delete temp->next_node;
    
    temp->next_node = nullptr;
    return return_data;
}

int LinkedList::deletion(int index){
    int ret_data{};
    if(index == 0){
        Node * temp = head;
        ret_data = head->m_data;
        head = head->next_node;
        delete temp;
        return ret_data;
    }

    Node * temp = head;
    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next_node;
    }
    Node * ptr = temp->next_node;
    ret_data = ptr->m_data;

    temp->next_node = temp->next_node->next_node;
    delete ptr;
    return ret_data;
}

int LinkedList::search(int value){
    Node * temp = head;

    while(temp != nullptr){
            if(temp->m_data == value){
                return 1;
            }
            temp = temp->next_node;
    }


    return 0;
}

void LinkedList::updation(int index, int new_value){
    Node * temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next_node;
    }
    temp->m_data = new_value;
}

int main(){
    LinkedList list;

    list.insertion(12);
    list.insertion(13);
    list.insertion(14);
    list.updation(1,333);

    // list.deletion(1);

    list.traversal();

    std::cout <<  list.search(14);

    return 0;
}