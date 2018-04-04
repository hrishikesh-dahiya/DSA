#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *n){

    while(n!=NULL){
        cout<<n->data<<'\t';
        n = n->next;
    }
    cout<<endl;
}

void push(struct Node** head_ref, int new_data){

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(){

    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    //struct Node* elements[10];

    head  = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node));
    first  = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = NULL;

    printList(head);

    // for(int i=0;i<10;i++){
    //     struct Node* elements[i] = (struct Node*) malloc(sizeof(struct Node));        
    //     elements[i]->data = i;
    //     elements[i]->next = elements[i+1];
    // }

    // for(int i=0;i<10;i++){
    //     cout<<elements[i]->data<<'\t';
    // }

    return 0;
}