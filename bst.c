// Amit Pawar
// A1-AIML
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
struct node {
    int data;
    struct node *left, *right;
};

// Queue Definition 
struct queue {
    struct node* arr[SIZE];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct queue *q) {
    q->front = q->rear = -1;
}
int isEmpty(struct queue *q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct queue *q, struct node *value) {
    if (q->rear == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

struct node* dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return NULL;
    }
    struct node *temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Create a new node 
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BFS function
void BFS(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    struct queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        struct node *current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(&q, current->left);
        if (current->right)
            enqueue(&q, current->right);
    }
    printf("\n");
}

int main() {
    struct node *root = createNode(37);
    root->left = createNode(38);
    root->right = createNode(46);
    root->left->left = createNode(83);
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = createNode(89);
    root->right->right->left = createNode(56);
    root->right->right->right = createNode(52); 

    printf("Applying BFS on Tree:\n");
    BFS(root);

    return 0;
}
