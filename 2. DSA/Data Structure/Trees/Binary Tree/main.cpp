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

int main()
{
    //Creating nodes
    struct node *root = createNode(20);
    struct node *first = createNode(33);
    struct node *second = createNode(76);
    struct node *third = createNode(98);
    struct node *fourth = createNode(21);

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

    return 0;
}