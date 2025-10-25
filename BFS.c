// Amit Pawar
// A1-AIML
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
struct node {
    int data;
    struct node *next;
};

// Graph definition
struct graph {
    int vertices;
    struct node *adjList[SIZE];
    int visited[SIZE];
};
struct queue {
    int arr[SIZE];
    int front;
    int rear;
};
void initQueue(struct queue *q) {
    q->front = q->rear = -1;
}
int isEmpty(struct queue *q) {
    return q->front == -1;
}
void enqueue(struct queue *q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}
int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Create a new adjacency list node
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct graph* createGraph(int vertices) {
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

// Add edge (directed)
void addEdge(struct graph *g, int src, int dest) {
    struct node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    // For undirected graph, also add reverse edge:
    // newNode = createNode(src);
    // newNode->next = g->adjList[dest];
    // g->adjList[dest] = newNode;
}

// Display graph adjacency list
void displayGraph(struct graph *g) {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < g->vertices; i++) {
        struct node *temp = g->adjList[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
// BFS function
void BFS(struct graph *g, int startVertex) {
    struct queue q;
    initQueue(&q);

    g->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        struct node *temp = g->adjList[current];
        while (temp) {
            int adjVertex = temp->data;
            if (g->visited[adjVertex] == 0) {
                g->visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
// Main function
int main() {
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct graph *g = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("\nEnter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    displayGraph(g);

    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(g, start);

    return 0;
}
