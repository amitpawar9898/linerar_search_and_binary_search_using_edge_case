// Amit Pawar
// A1-AIML
// Program to implement Depth First Search (DFS)
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct AdjList* array;
    int* visited;
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph undirected
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src since graph is undirected
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Recursive DFS function
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->array[vertex].head;
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
            DFS(graph, connectedVertex);
        temp = temp->next;
    }
}

// Function to print the adjacency list
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int vertices, edges, src, dest, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex);
    printf("\n");

    return 0;
}
