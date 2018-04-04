#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} T;

void inOrderWalk(T *root){
    if(root == NULL){
        return;
    } else {
        inOrderWalk(root->left);
        cout << root->data;
        inOrderWalk(root->right);
    }
}

int main() {
    T *root = new T;

    root->data = 6;
    root->left = new T;
    root->right = new T;
    root->parent = NULL;
    root->left->data = 5;
    root->left->left = new T;
    root->left->right = new T;
    root->left->left->data = 2;
    root->left->right->data = 5;
    root->right->data = 7;

    inOrderWalk(root);

    return 0;
}
