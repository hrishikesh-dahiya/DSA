#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int key){
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
        this->key = key;
    }
} Node;

int height(Node *node)
{
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int setBal(Node *node)
{
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *rightRotate(Node *node)
{
    Node *tmp = node->left;
    Node *tmp2 = tmp->right;

    tmp->right = node;
    node->left = tmp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    tmp->height = max(height(tmp->left), height(tmp->right)) + 1;

    //cout << "Rotated right at " << tmp->right->key << endl;
    return tmp;
}

Node *leftRotate(Node *node)
{
    Node *tmp = node->right;
    Node *tmp2 = tmp->left;

    tmp->left = node;
    node->right = tmp2;

    node->height = max(height(node->left), height(node->right)) + 1;
    tmp->height = max(height(tmp->left), height(tmp->right)) + 1;

    //cout << "Rotated left at " << tmp->left->key << endl;
    return tmp;    
}

Node *insert(Node *node, int key)
{
    if(node == NULL){
        return new Node(key);
    }

    if(key < node->key){
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int bal = setBal(node);

    if(bal > 1){
        if(key > node->left->key){
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    if(bal < -1){
        if(key < node->right->key){
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }

    return node;
}

Node *minValNode(Node *node)
{
    Node *current = node;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *node, int key)
{
    if(node == NULL){
        return NULL;
    }
    if(key < node->key){
        node->left = deleteNode(node->left, key);
    } else if(key > node->key){
        node->right = deleteNode(node->right, key);
    } else {
        if(node->left == NULL || node->right == NULL){
            Node *tmp = node->left ? node->left : node->right;

            if(tmp == NULL){
                tmp = node;
                node = NULL;
            } else {
                *node = *tmp;
            }
            free(tmp);
        } else {
            Node *tmp = minValNode(node->right);

            node->key = tmp->key;

            node->right = deleteNode(node->right, tmp->key);
        }
    }

    if(node == NULL){
        return NULL;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int bal = setBal(node);

    if(bal > 1){
        if(setBal(node->left) < 0){
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    if(bal < -1){
        if(setBal(node->right) > 0){
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

void printGivenLevel(Node *node, int level)
{
    if(node == NULL){
        cout << "- ";
        return;
    }
    if(level == 1){
        cout << node->key << " ";
    } else if(level > 1){
        printGivenLevel(node->left, level - 1);
        printGivenLevel(node->right, level -1);
    }
}

void printLevelOrder(Node *node)
{
    int h = height(node);
    for(int i=1;i<=h;i++){
        printGivenLevel(node, i);
        cout << endl;
    }    
}

int main()
{
    int n;
    queue<int> tree;

    cin >> n;

    int m = n;
    while(m--){
        int in;
        cin >> in;
        tree.push(in);
    }

    Node *root = NULL;

    m = n;
    while(m--){
        //cout << "Inserting " << tree.front() << endl;
        root = insert(root, tree.front());
        //cout << "Inserted " << tree.front() << endl;
        tree.pop();
    }

    printLevelOrder(root);

    int key;
    cin >> key;

    deleteNode(root, key);

    printLevelOrder(root);

    return 0;
}
