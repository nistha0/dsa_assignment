# Program 8: Sorting Algorithms with Performance Analysis

## Data Structures Used

**Dynamic Arrays:** Uses malloc to allocate arrays based on user input size

**Global Counters:** 
- `comparisons`: tracks number of comparisons
- `swaps`: tracks number of swaps/moves

## Functions Implemented

### Sorting Algorithms

**bubbleSort(int arr[], int n)** - Bubble Sort
- Repeatedly swaps adjacent elements if in wrong order
- Multiple passes through array
- Time: O(n²), Space: O(1)

**selectionSort(int arr[], int n)** - Selection Sort
- Finds minimum element and places it at beginning
- Divides array into sorted and unsorted portions
- Time: O(n²), Space: O(1)

**insertionSort(int arr[], int n)** - Insertion Sort
- Builds sorted array one element at a time
- Inserts each element into correct position
- Time: O(n²) worst case, O(n) best case, Space: O(1)

**mergeSort(int arr[], int n)** - Merge Sort
- Divide and conquer algorithm
- Recursively divides array and merges sorted halves
- Time: O(n log n), Space: O(n)

### Helper Functions

**merge()** - Merges two sorted subarrays for merge sort

**mergeSortHelper()** - Recursive helper for merge sort

**swap()** - Swaps two elements and increments swap counter

**resetCounters()** - Resets comparison and swap counters

**printArray()** - Displays array elements

## How main() Works

1. Asks user for array size N
2. Generates N random integers between 1 and 1000
3. Displays menu to choose sorting algorithm
4. Shows array before sorting (first 20 elements)
5. Executes chosen sorting algorithm
6. Displays sorted array (first 20 elements)
7. Shows statistics: total comparisons and swaps

## Sample Output
```
Enter the number of elements (N): 50

Generating 50 random numbers between 1 and 1000...

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter your choice (1-4): 4

Before sorting (first 20 elements): 834 123 456 789 234 567 890 345 678 901 123 456 789 234 567 890 345 678 901 234 ...

Using Merge Sort...

After sorting (first 20 elements): 12 23 34 45 56 67 78 89 90 100 111 122 133 144 155 166 177 188 199 210 ...

--- Statistics ---
Total Comparisons: 248
Total Swaps: 295
```

## Algorithm Comparison

**Bubble Sort:** Simple but inefficient, many swaps

**Selection Sort:** Fewer swaps than bubble, same time complexity

**Insertion Sort:** Efficient for small/nearly sorted data

**Merge Sort:** Most efficient for large datasets, guaranteed O(n log n)