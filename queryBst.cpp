#include <iostream>

using namespace std;

typedef struct Node
{
    int key, size;
    Node *left, *right;
    Node(int key){
        this->key = key;
        this->size = 0;
        this->left = NULL;
        this->right = NULL;
    }
} T;

int getSize(Node *node)
{
    if(node == NULL){
        return 0;
    }
    return node->size;
}

T *insert(T *node, int key)
{
    if(node == NULL){
        return new T(key);
    }
    if(node->key == key){
        return node;
    }
    else if(node->key > key){
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    node->size = 1 + getSize(node->left) + getSize(node->right);
    return node;
}

int countSmaller(T *node, int key)
{
    if(node == NULL){
        return 0;
    }
    if(node->key == key){
        return getSize(node->left);
    }
    if(node->key > key){
        return countSmaller(node->left, key);
    }
    if(node->key < key){
        return 1 + getSize(node->left) + countSmaller(node->right, key);
    }
}

int kthlargest(T *node, int key)
{

}

int main()
{
    int q, type, key;
    T *root = NULL;

    cin >> q;

    while(q--){
        cin >> type;
        cin >> key;
        if(type == 1){
            root = insert(root, key);
        } else if(type == 2){
            cout << countSmaller(root, key) << endl;
        } else {
            continue;
        }
    }

    cout << root->size << endl;

    return 0;
}
