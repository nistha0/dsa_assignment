#include <stdio.h>
#include <limits.h>

#define V 6
#define INF INT_MAX

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;
    
    for(int v = 0; v < V; v++) {
        if(visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int n, int src) {
    printf("\nShortest distances from source vertex %d:\n", src);
    printf("Vertex\t\tDistance from Source\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t", i);
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];
    
    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[src] = 0;
    
    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        
        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INF 
               && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printSolution(dist, V, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    
    printf("Graph represented as adjacency matrix:\n");
    printf("(0 means no edge, number means weight)\n\n");
    
    printf("   ");
    for(int i = 0; i < V; i++)
        printf("%3d ", i);
    printf("\n");
    
    for(int i = 0; i < V; i++) {
        printf("%d: ", i);
        for(int j = 0; j < V; j++) {
            if(graph[i][j] == 0)
                printf("  - ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    
    dijkstra(graph, 0);
    
    return 0;
}