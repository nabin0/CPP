#include<iostream>

struct Node{
    int data;
    struct Node * left;
    Node *right;
};


class BST{
    struct Node * root;

    void insertNode(Node* root, int data);
    bool searchNode(Node* root, int);
    Node* deleteNode(Node* root, int);
    void inOrderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);

    Node * inorderPredecessor(Node * root); // REturns the inorder predecessor of give node

    protected:
    Node* createNode(int data){ // Utility function to create node
        Node* new_node = new Node;
        new_node->data = data;
        new_node->left = new_node->right = nullptr;

        return new_node;
    }

    public:
    BST(): root{nullptr}{}

    // Binary Search Operations
    void insertNode(int data);
    Node* deleteNode(int data);
    bool searchNode(int data);

    // Traversal in BST
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};


// Insert node in BST
void BST::insertNode(int data){
    if(root!=nullptr){
        insertNode(root, data);
    }else{
        root = createNode(data);
    }
}

void BST::insertNode(Node *root, int data){
    // If data is smaler than root then insert into left tree
    if(data < root->data){
        if(root->left != nullptr){
        insertNode(root->left, data);
        }else{
            root->left = createNode(data);
        }
    }else{ // If data is greater than current root data then insert in the right tree
        if(root->right != nullptr){
        insertNode(root->right, data);
        }else{
            root->right = createNode(data);
        }
    }
}

// Deleteion of a node in BST

Node* BST::deleteNode(int data){
    if(root){
        return deleteNode(root, data);
    }else{
        return nullptr;
    }
}

Node* BST::deleteNode(Node * root, int data){
    if(root == nullptr){
        return root;
    }

    // If root have No childern nodes
    if(root->left == nullptr && root->right == nullptr){
        delete root;
        root = nullptr;
        return root;
    }

    // Find the node to be deleted
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{// When found delete it
        Node * temp_node = inorderPredecessor(root);
        root->data = temp_node->data;
        root->left = deleteNode(root->left, temp_node->data);
    }

    return root;
}

Node * BST::inorderPredecessor(Node * root){
    root = root->left;
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

// Searching in the BST
bool BST::searchNode(int data){
    if(root){
      return searchNode(root,data);
    }else{
        std::cout << "Cannot find the Node int Tree" << std::endl;
        return false;
    }
}

bool BST::searchNode(Node* root, int data){
    bool result = false;

    if(data == root->data){
        result = true;
        return result;
    }

    if(data < root->data){
        if(root->left){
            searchNode(root->left, data);
        }else{
            result = false;
        }
    }else{
        if(root->right){
        searchNode(root->right, data);
        }else{
            result = false;
        }
    }
    return result;
}


// Inorder Traversal in the BST
void BST::inOrderTraversal(Node* root){
    if(root!=nullptr){
        inOrderTraversal(root->left);
        std::cout << root->data << " " ;
        inOrderTraversal(root->right);
    }
}
void BST::inOrderTraversal(){
    if(root == nullptr){
        std::cout << "The tree is empty." << std::endl;
        return;
    }else{
        inOrderTraversal(root);
    }
}

// Pre order traversal

void BST::preOrderTraversal(){
    if(!root){
        std::cout << "The tree is empty." << std::endl;
        return;
    }else{
        preOrderTraversal(root);
    }
}

void BST::preOrderTraversal(Node *root){
    if(root){
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal

void BST::postOrderTraversal(){
    if(!root){
        std::cout << "The tree is empty." << std::endl;
        return;
    }else{
        postOrderTraversal(root);
    }
}

void BST::postOrderTraversal(Node *root){
    if(root){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

int main(){
    
    BST t;
    t.insertNode(12);
    t.insertNode(13);
    t.insertNode(7);
    t.insertNode(3);

    t.deleteNode(12);

    std::cout << std::boolalpha << t.searchNode(122) << std::endl;
    
    std::cout << "\nTraversal of BST: \n";
    std::cout <<"Inorder Traversal: ";
    t.inOrderTraversal();
    std::cout <<'\n';
    std::cout <<"Pre-order Traversal: ";
    t.preOrderTraversal();
    std::cout <<'\n';
    std::cout <<"Post-order Traversal: ";
    t.postOrderTraversal();
    std::cout <<'\n';
    return 0;
}


/*
// Iterative method to insert node (to use these comment other definiton of the methods)
void BST::insertNode(int data){

    if(root == nullptr){ // If there is no root present create root
        struct Node * new_node = createNode(data);
        root = new_node;
        return;
    }

    Node *temp_root = root;
    Node * prev;
    while(temp_root!= nullptr){
        prev = temp_root;
        // if data is already in the tree return 
        if(data == temp_root->data){
            std::cout << "Cannot insert, Data is already inserted!!" << std::endl;
            return;
        }else if(data < temp_root->data){ //Check if the data is lesser than root
            temp_root = temp_root->left;
        }else if(data > temp_root->data){
            temp_root = temp_root->right;
        }
    }

    Node * new_node = createNode(data);

    if(prev->data > data){
        prev->left = new_node;
    }else{
        prev->right = new_node;
    }
}

*/