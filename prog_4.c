#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterNode(struct Node* prevNode, int data) {
    if(prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    
    if(newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteNode(struct Node** head, struct Node* delNode) {
    if(*head == NULL || delNode == NULL) {
        return;
    }
    
    if(*head == delNode) {
        *head = delNode->next;
    }
    
    if(delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    if(delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    free(delNode);
}

void printList(struct Node* head) {
    printf("List: ");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* findNode(struct Node* head, int value) {
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;
    
    printf("Creating doubly linked list: 10, 20, 30, 40\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printList(head);
    
    printf("\nInserting 25 after node with value 20\n");
    struct Node* node20 = findNode(head, 20);
    insertAfterNode(node20, 25);
    printList(head);
    
    printf("\nDeleting node with value 30\n");
    struct Node* node30 = findNode(head, 30);
    deleteNode(&head, node30);
    printList(head);
    
    return 0;
}