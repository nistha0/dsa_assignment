# Program 4: Doubly Linked List Implementation

## Data Structures Used

### Node Structure
```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
```
- `data`: integer value stored in node
- `prev`: pointer to previous node
- `next`: pointer to next node

## Functions Implemented

### createNode(int data)
- Allocates memory for new node
- Initializes data and sets both pointers to NULL
- Returns pointer to created node

### insertAtEnd(struct Node** head, int data)
- Adds new node at end of list
- Updates both next and prev pointers
- Handles empty list case

### insertAfterNode(struct Node* prevNode, int data)
- **Main insert function** - inserts new node after given node
- Creates new node
- Updates four pointers to maintain double links
- Handles edge case when inserting at end

### deleteNode(struct Node** head, struct Node* delNode)
- **Main delete function** - removes given node from list
- Updates prev and next pointers of adjacent nodes
- Handles three cases: deleting head, middle, or tail
- Frees memory of deleted node

### printList(struct Node* head)
- Traverses list from head to end
- Prints data of each node

### findNode(struct Node* head, int value)
- Helper function to find node with specific value
- Returns pointer to node if found, NULL otherwise

## How main() Works

1. Creates empty doubly linked list
2. Inserts four nodes (10, 20, 30, 40) at end
3. Demonstrates insertAfterNode by inserting 25 after node 20
4. Demonstrates deleteNode by deleting node with value 30
5. Prints list after each operation

## Sample Output
```
Creating doubly linked list: 10, 20, 30, 40
List: 10 20 30 40 

Inserting 25 after node with value 20
List: 10 20 25 30 40 

Deleting node with value 30
List: 10 20 25 40 
```

## Key Differences from Singly Linked List

- Each node has two pointers instead of one
- Can traverse in both directions
- Insertion and deletion require updating more pointers
- Extra memory overhead for prev pointer