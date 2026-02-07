# Program 6: Min Heap and Max Heap Implementation

## Data Structures Used

Uses simple integer array to represent heap. Heap property is maintained through parent-child relationships using array indices.

**Index relationships:**
- Parent of node at index i: (i-1)/2
- Left child of node at index i: 2*i + 1
- Right child of node at index i: 2*i + 2

## Functions Implemented

### Helper Function

**swap(int* a, int* b)** - Swaps two integers using pointers

### Min Heap Functions

**minHeapify(int arr[], int n, int i)** - Maintains min heap property
- Compares node with left and right children
- If child is smaller, swaps and recursively heapifies
- Ensures parent is smaller than both children

**buildMinHeap(int arr[], int n)** - Builds complete min heap from unsorted array
- Starts from last non-leaf node (n/2 - 1)
- Calls minHeapify on each node going backwards
- Bottom-up approach

### Max Heap Functions

**maxHeapify(int arr[], int n, int i)** - Maintains max heap property
- Compares node with children
- If child is larger, swaps and recursively heapifies
- Ensures parent is larger than both children

**buildMaxHeap(int arr[], int n)** - Builds complete max heap
- Same approach as buildMinHeap but with max heap property
- Starts from last non-leaf node

### Utility

**printArray(int arr[], int n)** - Displays array elements

## How main() Works

1. Creates unsorted array
2. Displays original array
3. Builds min heap and displays result
4. Creates same array again
5. Builds max heap and displays result

## Sample Output
```
Original array: 12 11 13 5 6 7 
Min Heap: 5 6 7 12 11 13 

Original array: 12 11 13 5 6 7 
Max Heap: 13 11 12 5 6 7 
```

## Heap Properties

**Min Heap:** Parent node is always smaller than or equal to its children. Root contains minimum element.

**Max Heap:** Parent node is always greater than or equal to its children. Root contains maximum element.

**Time Complexity:** Building heap is O(n), heapify operation is O(log n)