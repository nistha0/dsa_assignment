# Program 3: Reverse Traversal in Linked List

## Data Structures Used

### Node Structure
```c
struct Node {
    int data;
    struct Node* next;
};
```
- `data`: stores integer value
- `next`: pointer to next node in list

## Functions Implemented

### createNode(int data)
- Allocates memory for new node
- Initializes data and sets next to NULL
- Returns pointer to new node

### insertAtEnd(struct Node** head, int data)
- Creates new node with given data
- If list empty, makes it the head
- Otherwise traverses to end and adds new node

### printForward(struct Node* head)
- Iterative traversal from head to end
- Prints each node's data

### reverseTraversal(struct Node* head)
- **Recursive function** for reverse traversal
- Base case: if node is NULL, return
- Recursive case: call function on next node, then print current data
- Uses call stack to achieve reverse order

### printReverse(struct Node* head)
- Wrapper function that calls reverseTraversal
- Adds formatting for output

## How main() Works

1. Initializes empty linked list (head = NULL)
2. Inserts five nodes with values 10, 20, 30, 40, 50
3. Displays forward traversal
4. Displays reverse traversal using recursive algorithm

## Sample Output
```
Creating linked list with values: 10, 20, 30, 40, 50

Forward traversal: 10 20 30 40 50 
Reverse traversal: 50 40 30 20 10 
```

## Algorithm Explanation

The reverse traversal uses recursion. The function calls itself with the next node before printing current node's data. This causes the print statements to execute in reverse order as the recursion unwinds from the call stack.