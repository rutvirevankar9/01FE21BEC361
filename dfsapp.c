#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Stack {
    int items[MAX_VERTICES];
    int top;
};

void initializeGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void DFS(struct Graph* graph, int startVertex, int endVertex, int visited[], struct Stack* pathStack) {
    push(pathStack, startVertex);
    visited[startVertex] = 1;

    if (startVertex == endVertex) {
        printf("Path Found: ");
        while (!isEmpty(pathStack)) {
            printf("%d ", pop(pathStack));
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[startVertex][i] == 1 && visited[i] == 0) {
            DFS(graph, i, endVertex, visited, pathStack);
        }
    }

    visited[startVertex] = 0;  // Reset visited flag for backtracking
    pop(pathStack);
}

int main() {
    const char* inputFilename = "graph.txt";
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", inputFilename);
        return 1;
    }

    int numVertices;
    fscanf(inputFile, "%d", &numVertices);

    struct Graph graph;
    initializeGraph(&graph, numVertices);

    int src, dest;
    while (fscanf(inputFile, "%d %d", &src, &dest) != EOF) {
        addEdge(&graph, src, dest);
    }

    fclose(inputFile);

    int startVertex, endVertex;
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);
    printf("Enter the end vertex: ");
    scanf("%d", &endVertex);

    int visited[MAX_VERTICES] = {0};
    struct Stack pathStack;
    pathStack.top = -1;

    DFS(&graph, startVertex, endVertex, visited, &pathStack);

    return 0;
}

