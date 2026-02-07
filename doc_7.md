# Program 7: Dijkstra's Shortest Path Algorithm

## Data Structures Used

**Adjacency Matrix:** 2D array representing weighted graph. graph[i][j] contains weight of edge from vertex i to j. Zero means no edge.

**Distance Array:** Stores shortest distance from source to each vertex.

**Visited Array:** Tracks which vertices have been processed.

## Functions Implemented

### minDistance(int dist[], int visited[])
- Finds vertex with minimum distance value
- Only considers unvisited vertices
- Returns index of vertex with minimum distance
- Used to select next vertex to process

### dijkstra(int graph[V][V], int src)
- **Main algorithm implementation**
- Initializes all distances to infinity except source (0)
- Iteratively:
  - Selects unvisited vertex with minimum distance
  - Marks it as visited
  - Updates distances of adjacent vertices if shorter path found
- Uses greedy approach

### printSolution(int dist[], int n, int src)
- Displays final shortest distances
- Shows distance from source to all vertices
- Handles infinity case for unreachable vertices

## How main() Works

1. Creates weighted graph using adjacency matrix
2. Graph has 6 vertices with various edge weights
3. Displays graph structure
4. Calls Dijkstra's algorithm with vertex 0 as source
5. Shows shortest paths to all other vertices

## Sample Output
```
Graph represented as adjacency matrix:
(0 means no edge, number means weight)

     0   1   2   3   4   5 
0:   -   4   -   -   -   - 
1:   4   -   8   -   -   - 
2:   -   8   -   7   -   4 
3:   -   -   7   -   9  14 
4:   -   -   -   9   -  10 
5:   -   -   4  14  10   - 

Shortest distances from source vertex 0:
Vertex		Distance from Source
0		0
1		4
2		12
3		19
4		28
5		16
```

## Algorithm Explanation

Dijkstra's algorithm finds shortest path from source to all vertices in weighted graph with non-negative edges. It maintains two sets: visited and unvisited vertices. Repeatedly selects unvisited vertex with minimum distance, marks it visited, and updates distances of neighbors through relaxation.

**Time Complexity:** O(V²) with adjacency matrix