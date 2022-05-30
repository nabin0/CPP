#include<iostream>
#include<queue>
using namespace std;

//Huffmans Tree Node
struct HuffmansTreeNode{
    char data;
    int frequency;
    struct HuffmansTreeNode *left, *right;

    HuffmansTreeNode(char data, int freq) : data(data), frequency(freq), left(NULL), right(NULL){}
};

//For comparison of two nodes
struct Compare
{
    bool operator()(const HuffmansTreeNode *a, const HuffmansTreeNode *b){
        return a->frequency > b->frequency;
    }
};

//Print data (wiill print bin code for a given character)

void print_data(const struct HuffmansTreeNode * root, string str){
    if(!root){return; }

    if(root->data != '$'){
        cout << root->data << " : " << str << endl;
    }
    print_data(root->left, str + '0');
    print_data(root->right, str + '1');
}


// Build Huffmans Tree
void huffmansEncoding(char arr[], int freq[], int size){

    struct HuffmansTreeNode * left, * right, *temp;

    // Create a MinHeap
    priority_queue<HuffmansTreeNode*, vector<HuffmansTreeNode*>, Compare > minHeap;

    // Make and put all HuffmansTree Node in the minheap
    for(int i = 0; i < size; i++)
        minHeap.push(new HuffmansTreeNode(arr[i], freq[i]));

    //Iterate until the size of min heap becomes 1
    while(minHeap.size() != 1){
        //Extract two min items from the min Heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new HuffMansNode which is equal to the above two min nodes freq and store it into minHeap
        temp = new HuffmansTreeNode('$', left->frequency + right->frequency); // '$' will help into  saperating in leaf and inter node
        temp->left = left;
        temp->right = right;

        minHeap.push(temp);
     }

    print_data(minHeap.top(), "");
}

int main(){

    char arr[] = {'a','b','c','d'};
    int freq[] = {10,5,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    huffmansEncoding(arr, freq, n);

    return 0;
}


