#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph structure
typedef struct
{
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
void enqueue(Queue* q, int);
int dequeue(Queue* q);
bool isQueueEmpty(Queue* q);
void addEdge(Graph* g, int source, int destination);
void readGraph(Graph* g, FILE* file);
void writeBFS(Graph* g, int startVertex, FILE* file);
void bfs(Graph* g, int startVertex, bool visited[]);

// Queue operations
void enqueue(Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

bool isQueueEmpty(Queue* q) {
    return q->rear < q->front;
}

// Add an edge to the graph
void addEdge(Graph* g, int source, int destination) {
    g->vertices[source][destination] = 1;
    g->vertices[destination][source] = 1;
}

// Read the graph from a file
void readGraph(Graph* g, FILE* file) {
    int numVertices, numEdges;
    fscanf(file, "%d", &numVertices);

    // Initialize the graph
    g->numVertices = numVertices;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->vertices[i][j] = 0;
        }
    }

    fscanf(file, "%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        fscanf(file, "%d %d", &source, &destination);
        addEdge(g, source, destination);
    }
}

// Write the BFS traversal to a file
void writeBFS(Graph* g, int startVertex, FILE* file) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    Queue q;
    q.front = 0;
    q.rear = -1;

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        fprintf(file, "%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->vertices[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    FILE* inputFile = fopen("inputo.txt", "r");
    FILE* outputFile = fopen("outputo.txt", "w");

    Graph graph;
    readGraph(&graph, inputFile);

    int startVertex;
    fscanf(inputFile, "%d", &startVertex);

    writeBFS(&graph, startVertex, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
