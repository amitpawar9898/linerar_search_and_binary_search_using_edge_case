#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* stack[20];
int top = -1;

// Push to stack
void push(struct node* n) {
    if (top == 19) { printf("Stack Overflow!\n"); return; }
    stack[++top] = n;
}

// Pop  stack
struct node* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

// inorder traversal
void inorder(struct node* root) {
    struct node* current = root;
    printf("Inorder Traversal: ");
    while (current != NULL || top != -1) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }
        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}
int search(struct node* root, int key) {
    if (!root) return 0;
    push(root);
    while (top != -1) {
        struct node* temp = pop();
        if (temp->data == key) 
        return 1;
        if (temp->right) push(temp->right);
        if (temp->left) push(temp->right);
        
    }
    return 0;
}

int main() {
    struct node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);
    root->right->right = createNode(70);

    inorder(root);

    // Search for a value
    int key = n;
    if (search(root, key))
        printf("%d found in tree.\n", key);
    else
        printf("%d not found in tree.\n", key);

    return 0;
}
