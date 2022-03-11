#include<iostream>
#include<queue>
#include<stack>

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int data){
        val = data;
        left = right = nullptr;
    }
};

class Bst{
    private:
    Node * root = nullptr;

    protected:
    void inorder(Node * node);
    void preorder(Node * node);
    void postorder(Node * node);
    Node * remove(Node * node, int data);
    Node * search(Node *node, int data);

    public:
    void insert(int data);
    void remove(int data);

    // Iterative Traversal
    void iterInorderTraverse();
    void iterPreorderTraverse();
    void iterPostorderTraverse();

    // Recursive Tarversal
    void preorder(); 
    void postorder();
    void inorder();

    // Level Order Traversal
    void levelTraversal();

    //Searching Recursive
    Node * search(int data);

    // Searching Iterative
    Node * iterSearch(int data);
};

// Insert IN BST
void Bst::insert(int data){
    Node * newNode = new Node(data);
    if(root == nullptr){ // If Its the first insertion
        root = newNode;
        return;
    }

    Node * temp = root;
    while(temp){
        if(temp->val < data){
            if(temp->right){
                temp = temp->right;
            }else{
                temp->right = newNode;
                return;
            }
        }else if(temp->val > data){
            if(temp->left){
                temp = temp->left;
            }
            else{
                temp->left = newNode;
                return;
            }
        }else{
            std::cout << "Duplicate input not allowed!!!" << std::endl;
        }
    }
}

// Inorder Predecessor
Node * inorderPredecessor(struct Node *node){
    node = node->left;
    while (node && node->right)
    {
        node = node->right;
    }
    return node;
}

// Remove iterative function
Node* Bst::remove(Node * node, int data){
    Node * ipress;
    if(root == nullptr){
        return nullptr;
    }
    if((node->left == nullptr && node->right == nullptr)  && node->val == data){
        delete node;
        return nullptr;
    }

    if(node->val < data){
       node->right = remove(node->right, data);
    }else if(node->val > data){
        node->left = remove(node->left, data);
    }else{
        ipress = inorderPredecessor(node);
        node->val = ipress->val;
        node->left = remove(node->left, ipress->val);
    }
    return node;
}
void Bst::remove(int data){
    remove(root,data);
}


/**
 # Recursive Traversals
**/

// Inorder Tarversal
void Bst::inorder(Node * node){
    if(node){
        inorder(node->left);
        std::cout << node->val << ' ';
        inorder(node->right);
    }
}
void Bst::inorder(){
    if(root){
        inorder(root);
        std::cout << std::endl;
    }else{
        std::cout << "Tree is Empty!!!" << std::endl;
        return;
    }
}

// Preorder Traversal
void Bst::preorder(Node * node){
    if(node){
        std::cout << node->val << ' ';
        preorder(node->left);
        preorder(node->right);
    }
}

void Bst::preorder(){
    if(root){
        preorder(root);
        std::cout << std::endl;
    }else{
        std::cout << "Tree is Empty!!!" << std::endl;
    }
}

// Postorder Traversal
void Bst::postorder(Node * node){
    if(node){
        postorder(node->left);
        postorder(node->right);
        std::cout << node->val << ' ';
    }
}

void Bst::postorder(){
    if(root){
        postorder(root);
        std::cout << std::endl;
    }else{
        std::cout << "Tree is Empty!!!" << std::endl;
    }
}

// Level order Traversal
void Bst::levelTraversal(){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->val << std::endl;
    }
    Node * temp = root;
    std::queue<Node *> q;
    q.push(temp);
    while(!q.empty()){
        Node * frontItem = q.front();
        q.pop();
        std::cout << frontItem->val << ' ';
        if(frontItem->left)
            q.push(frontItem->left);
        if(frontItem->right)
            q.push(frontItem->right);
    }
    std::cout << std::endl;
}


/*
#Iterative Traversal
*/

// Inorder Traversal
void Bst::iterInorderTraverse(){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->val << std::endl;
    }

    Node* temp = root;
    std::stack<Node*> st;
    while(!st.empty() || temp){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        if(!st.empty()){
            Node * top = st.top();
            std::cout << top->val << ' ';
            st.pop();
            if(top->right){
                temp = top->right;
            }
        }
    }
    std::cout << std::endl;
}

//Preorder Traversal
void Bst::iterPreorderTraverse(){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->val << std::endl;
    }

    std::stack<Node *> s;
    Node * temp = root;
    while(!s.empty() || temp){
        while(temp){
        std::cout << temp->val << ' ';
        if(temp->right)
            s.push(temp->right);
        temp= temp->left;
        }
        if(!s.empty()){
            Node * top = s.top();
            s.pop();
            temp = top;
        }
    }
    std::cout << std::endl;
}

// Post-order Traversal
void Bst::iterPostorderTraverse(){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->val << std::endl;
    }

    std::stack< Node*> st;
    Node * temp = root;
    while(temp || !st.empty()){
        while(temp){
            if(temp->right)
                st.push(temp->right);
            st.push(temp);
            temp = temp->left;
        }
        if(!st.empty()){
            Node * top = st.top();
            st.pop();
            if(!st.empty()){
                if(top->right == st.top()){
                    Node * newTop = st.top();
                    st.pop();
                    st.push(top);
                    temp = newTop;
                }else{
                    std::cout << top->val << ' ';
                    temp = nullptr;
                }
            }else{
                std::cout << top->val << ' ';
                temp = nullptr;
            }
            
        }
    }
    std::cout << std::endl;
}

/*
#Recursive Search
*/
Node * Bst::search(Node * node, int data){
    if(node == nullptr){
        return nullptr;
    }
    if(node->val == data){
        return node;
    }else if(node->val > data){
        return search(node->left, data);
    }else{
        return search(node->right, data);
    }
    return nullptr;
}

Node * Bst::search(int data){
    if(root == nullptr){
        return nullptr;
    }
    Node * res = search(root, data);
    return res;
}

// Iterative Search
Node * Bst::iterSearch(int data){
    if(root == nullptr)
        return nullptr;
    
    Node * res = nullptr;
    Node * temp = root;
    while(temp){
        if(temp->val == data){
            return temp;
        }else if(temp->val < data){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    return nullptr;
}

// Driver code
int main(){
    Bst t;
    t.insert(12);
    t.insert(2);
    t.insert(7);
    t.insert(71);
    t.insert(23);

    // t.remove(7);

    // Recursive Traversals
    t.inorder();
    t.preorder();
    t.postorder();

    std::cout << std::endl;

    // Itereative Traversal
    t.iterInorderTraverse();
    t.iterPreorderTraverse();
    t.iterPostorderTraverse();

    std::cout << std::endl;

    // Level order Traversal (BFS)
    t.levelTraversal();

    //Searching
    Node * res = t.search(7);
    res = t.iterSearch(7);

    if(res){
        std::cout << "Data Found : " << res->val << std::endl;
    }else{
        std::cout << "Data Not Found : NULL"  << std::endl;
    }

    return 0;
}