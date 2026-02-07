#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};

void initGraph(struct Graph* g, int v) {
    g->vertices = v;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // undirected graph
}

void printGraph(struct Graph* g) {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for(int i = 0; i < g->vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < g->vertices; i++) {
        printf("%d ", i);
        for(int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if(q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    struct Queue q;
    initQueue(&q);
    
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    while(!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        for(int i = 0; i < g->vertices; i++) {
            if(g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for(int i = 0; i < g->vertices; i++) {
        if(g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    initGraph(&g, 6);
    
    printf("Creating graph with 6 vertices (0-5)\n");
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);
    
    printGraph(&g);
    
    printf("\n");
    BFS(&g, 0);
    DFS(&g, 0);
    
    return 0;
}