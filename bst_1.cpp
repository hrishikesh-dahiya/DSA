#include<iostream>

using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
} T ;

T *newNode(int key)
{
    T *temp = new T(key);
    return temp;
}

T* insert(T* node, int key)
{
    if(node == NULL){
        node = newNode(key);
        return node;
    }

    if(key < node->key){
        node->left = insert(node->left, key);
    } else if(key > node->key){
        node->right = insert(node->right, key);
    }

    return node;
}

int size(T *node)
{
    if(node == NULL){
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

int diff(T *node)
{
    return size(node->left) - size(node->right);
}

void preOrderIterativeDiff(T *root){
    cout << diff(root) << " ";
    if(root->left != NULL){
        preOrderIterativeDiff(root->left);
    }
    if(root->right != NULL){
        preOrderIterativeDiff(root->right);
    }
}


int main()
{
    int t, n, key;
    T *root = NULL;

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n;
        cin >> key;
        root = newNode(key);
        for(int j=0;j<n-1;j++){
            cin >> key;
            insert(root, key);
        }
        preOrderIterativeDiff(root);
        cout << endl;
    }
}
