#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = new struct node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//Traversal Functions
void preOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

//Searching in Binary tree
struct node *searchBst(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return searchBst(root->left, key);
    }
    else
    {
        return searchBst(root->right, key);
    }
}

struct node *searchBstIterMethd(struct node *root, int key) //Iterative way to search element in BST
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

//Insertion in a BST
void insertInBst(struct node *root, int data)
{
    struct node *prevPtr;
    while (root != NULL)
    {
        prevPtr = root;
        if (data == root->data)
        {
            cout << "Cannot insert " << data << " is already in the BST" << endl;
            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else if (data > root->data)
        {
            root = root->right;
        }
    }

    struct node *newNode = createNode(data);

    if (prevPtr->data > data)
        prevPtr->left = newNode;
    else
        prevPtr->right = newNode;
}

//Deletion in BST

struct node *inorderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletion(struct node *root, int key)
{
    struct node *iprss;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    //Finding the element in the Tree
    if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        //Deletion tactics
        iprss = inorderPredecessor(root);
        root->data = iprss->data;
        root->left = deletion(root->left, iprss->data);
    }
    return root;
}

int main()
{
    //Creating nodes
    struct node *root = createNode(50);
    struct node *first = createNode(45);
    struct node *second = createNode(55);
    struct node *third = createNode(34);
    struct node *fourth = createNode(48);

    //Linking nodes
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    //Calling pre order traversal
    preOrderTraversal(root);
    cout << endl;

    //Calling Post-order traversal
    postOrderTraversal(root);
    cout << endl;

    //Calling In-order traversal
    inOrderTraversal(root);
    cout << endl;

    //Insertion in BST
    insertInBst(root, 33);

    //Search function
    struct node *ptr = new struct node;
    ptr = searchBst(root, 33);
    ptr = searchBstIterMethd(root, 555);

    //Deletion
    deletion(root, 48);

    inOrderTraversal(root);
    cout << endl;

    if (ptr != NULL)
        cout << ptr->data << endl;
    else
        cout << "Not found!!!" << endl;

    cout << root->left->left->left->data << endl; //will give 33
    return 0;
}