//Amit pawar
//A1-Aiml
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjList;
};
// create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjList[v];
        printf("\nVertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
    printf("\n");
}

// Function to insert a new node vertex
void insertVertex(struct Graph** graphRef) {
    struct Graph* graph = *graphRef;
    int newVertices = graph->numVertices + 1;

    graph->adjList = (struct Node**)realloc(graph->adjList, newVertices * sizeof(struct Node*));
    graph->adjList[newVertices - 1] = NULL;
    graph->numVertices = newVertices;

    printf("\nInserted new vertex %d successfully.\n", newVertices - 1);
}

// Function to delete a vertex node
void deleteVertex(struct Graph* graph, int vertex) {
    if (vertex >= graph->numVertices) {
        printf("Vertex %d does not exist!\n", vertex);
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (i == vertex) continue;
        struct Node* temp = graph->adjList[i];
        struct Node* prev = NULL;

        while (temp) {
            if (temp->vertex == vertex) {
                if (prev)
                    prev->next = temp->next;
                else
                    graph->adjList[i] = temp->next;

                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    struct Node* temp = graph->adjList[vertex];
    while (temp) {
        struct Node* del = temp;
        temp = temp->next;
        free(del);
    }
    graph->adjList[vertex] = NULL;

    printf("\nDeleted vertex %d successfully.\n", vertex);
}

int main() {
    int vertices = 4;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("Original Graph:\n");
    printGraph(graph);

    // Insert new vertex (4)
    insertVertex(&graph);
    addEdge(graph, 2, 4);  

    printf("\nGraph After Inserting Vertex 4:\n");
    printGraph(graph);

    // Delete vertex 3
    deleteVertex(graph, 3);

    printf("\nGraph After Deleting Vertex 3:\n");
    printGraph(graph);

    return 0;
}
