#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100


typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Graph representation using adjacency matrix
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initializeGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->vertices[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    if (src >= 0 && src < g->numVertices && dest >= 0 && dest < g->numVertices) {
        g->vertices[src][dest] = 1;
        g->vertices[dest][src] = 1;
    }
}

void bfs(Graph* g, int startVertex, FILE* outputFile) {
    bool visited[MAX_VERTICES] = { false };
    Queue q;
    initializeQueue(&q);

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        fprintf(outputFile, "%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->vertices[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    FILE* inputFile = fopen("inputt.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input.txt file.\n");
        return 1;
    }

    FILE* outputFile = fopen("outputt.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output.txt file.\n");
        return 1;
    }

    int numVertices;
    fscanf(inputFile, "%d", &numVertices);

    Graph graph;
    initializeGraph(&graph, numVertices);

    int src, dest;
    while (fscanf(inputFile, "%d %d", &src, &dest) != EOF) {
        addEdge(&graph, src, dest);
    }

    int startVertex;


    fscanf(inputFile, "%d", &startVertex);

    fprintf(outputFile, "BFS traversal starting from vertex %d: ", startVertex);
    bfs(&graph, startVertex, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("BFS traversal completed. Check the output.txt file.\n");

    return 0;
}
