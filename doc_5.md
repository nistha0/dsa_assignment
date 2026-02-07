# Program 5: Graph Traversal using BFS and DFS

## Data Structures Used

### Graph Structure
```c
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};
```
Adjacency matrix representation where adjMatrix[i][j] = 1 if edge exists between vertex i and j.

### Queue Structure (for BFS)
```c
struct Queue {
    int items[MAX];
    int front, rear;
};
```

## Functions Implemented

### Graph Operations

**initGraph(struct Graph* g, int v)** - Initializes graph with v vertices, sets all matrix values to 0

**addEdge(struct Graph* g, int src, int dest)** - Adds undirected edge by setting both adjMatrix[src][dest] and adjMatrix[dest][src] to 1

**printGraph(struct Graph* g)** - Displays adjacency matrix

### BFS Implementation

**BFS(struct Graph* g, int startVertex)** - Breadth First Search
- Uses queue data structure
- Visits vertices level by level
- Marks vertices as visited to avoid cycles
- Process: enqueue start vertex, dequeue and visit, enqueue all unvisited neighbors

### DFS Implementation

**DFS(struct Graph* g, int startVertex)** - Depth First Search wrapper

**DFSUtil(struct Graph* g, int vertex, int visited[])** - Recursive DFS helper
- Uses recursion (implicit stack)
- Visits vertex, then recursively visits all unvisited neighbors
- Goes deep into graph before backtracking

### Queue Operations

**enqueue/dequeue/isEmpty** - Standard queue operations for BFS

## How main() Works

1. Creates graph with 6 vertices (0 to 5)
2. Adds edges to form connected graph
3. Prints adjacency matrix representation
4. Performs BFS traversal from vertex 0
5. Performs DFS traversal from vertex 0

## Sample Output
```
Creating graph with 6 vertices (0-5)

Adjacency Matrix:
  0 1 2 3 4 5 
0 0 1 1 0 0 0 
1 1 0 0 1 1 0 
2 1 0 0 0 1 0 
3 0 1 0 0 0 1 
4 0 1 1 0 0 1 
5 0 0 0 1 1 0 

BFS Traversal starting from vertex 0: 0 1 2 3 4 5 
DFS Traversal starting from vertex 0: 0 1 3 5 4 2 
```

## Algorithm Comparison

**BFS:** Uses queue, explores neighbors level by level, finds shortest path in unweighted graph

**DFS:** Uses recursion/stack, explores as far as possible before backtracking, uses less memory for sparse graphs