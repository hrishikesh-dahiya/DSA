#include <iostream>

using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;
    int bal;
    bool isBalanced;
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->bal = 0;
        this->isBalanced = true;
    }
} T;

T *insert(T *root, int key)
{
    if(root == NULL){
        root = new T(key);
        //cout << "New Node " << key << endl;
        return root;
    }
    if(root->key > key){
        // if(root->left == NULL){
        //     root->bal --;
        // }
        //cout << "Left Node " << key << endl;
        root->left = insert(root->left, key);
        //cout << root-> key << " : " << root->bal << endl;
        // if(root->right != NULL){
        //     root->bal = root->bal + root->right->bal + root->left->bal;
        // } else {
        //     root->bal = root->bal + root->left->bal;
        // }
        // if(root->left != NULL){
        //     root->bal = root->bal + root->left->bal;
        // }
        //cout << root-> key << " : " << root->bal << endl;
        return root;
    }
    if(root->key < key) {
        // if(root->right == NULL){
        //     root->bal ++;
        // }
        //cout << "Right Node " << key << endl;
        root->right = insert(root->right, key);
        //cout << root-> key << " : " << root->bal << endl;
        // if(root->right != NULL){
        //     root->bal = root->bal + root->right->bal;
        // }
        // if(root->left != NULL){
        //     root->bal = root->bal + root->left->bal + root->right->bal;
        // } else {
        //     root->bal = root->bal + root->right->bal;
        // }
        //cout << root-> key << " : " << root->bal << endl;
        return root;
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int minNodes(int h)
{
    if(h == 1){
        return 1;
    }
    if(h == 2){
        return 2;
    }
    else{
        return 1 + minNodes(h-1) + minNodes(h-2);
    }
}

// T *update(T *root)
// {
//     if(root == NULL){
//         cout << "Root is NULL" << endl;
//         return root;
//     }
//     root->left = update(root->left);
//     root->bal = root->bal + root->left->bal - 1;
//     root->right = update(root->right);
//     root->bal = root->bal + root->right->bal + 1;
//     return root;
// }

int main()
{
    int t, n, key;
    cin >> t;
    while(t--){
        cin >> n;
        int m = n;
        //cout << "t : " << t << endl;

        T *root = NULL;

        while(n--){
            //cout << "n : " << n << endl;
            cin >> key;
            root = insert(root, key);
        }

        int h = height(root);
        int minN = minNodes(h);

        int isBal = 0;

        (m > minN) ? isBal = 1 : isBal = 0;

        cout << isBal << endl;

    }
}
