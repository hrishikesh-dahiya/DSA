#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void print(struct Node *n){

    while(n!=NULL){
        cout<<n->data<<'\t';
        n = n->next;
    }
    cout<<endl;
}

void push(struct Node *stack, int x)
{
    if(stack->data == 0 && stack->next == NULL){
        stack->data = x;
    } else {
        struct Node *onTop = new Node;
        onTop->data = stack->data;
        onTop->next = stack->next;
        stack->next = onTop;
        stack->data = x;
    }
}

void pop(struct Node *stack)
{
    if(stack->next == NULL && stack->data == 0){
        cout << "Cannot pop(), stack is empty"<<endl;
    } else if(stack->next == NULL){
        stack->data = 0;
    } else {
        struct Node *temp;
        temp = stack->next;
        stack->next = NULL;
        stack->next = temp->next;
        stack->data = temp->data;
    }
}

int main()
{
    struct Node *stack = new Node;

    push(stack, 5);
    push(stack, 6);
    push(stack, 9);
    print(stack);
    pop(stack);
    print(stack);
    push(stack, 10);
    push(stack, 3);
    print(stack);
    pop(stack);
    print(stack);
    push(stack, 3);
    push(stack, 3);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    pop(stack);
    print(stack);
    push(stack, 5);
    push(stack, 6);
    push(stack, 9);
    print(stack);
    

}
