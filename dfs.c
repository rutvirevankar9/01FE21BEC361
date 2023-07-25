#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
void addEdge(Graph* g, int source, int destination);
void readGraph(Graph* g, FILE* file);
void writeDFS(Graph* g, int startVertex, FILE* file);
void dfs(Graph* g, int currentVertex, bool visited[], FILE* file);

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

// Write the DFS traversal to a file
void writeDFS(Graph* g, int startVertex, FILE* file) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    dfs(g, startVertex, visited, file);
}

// Perform DFS traversal recursively
void dfs(Graph* g, int currentVertex, bool visited[], FILE* file) {
    visited[currentVertex] = true;
    fprintf(file, "%d ", currentVertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->vertices[currentVertex][i] == 1 && !visited[i]) {
            dfs(g, i, visited, file);
        }
    }
}

int main() {
    FILE* inputFile = fopen("inputdf.txt", "r");
    FILE* outputFile = fopen("outputdf.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Graph graph;
    readGraph(&graph, inputFile);

    int startVertex;
    fscanf(inputFile, "%d", &startVertex);

    writeDFS(&graph, startVertex, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
