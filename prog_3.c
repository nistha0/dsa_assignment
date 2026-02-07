#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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
}

void printForward(struct Node* head) {
    printf("Forward traversal: ");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraversal(struct Node* head) {
    if(head == NULL)
        return;
    
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

void printReverse(struct Node* head) {
    printf("Reverse traversal: ");
    reverseTraversal(head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    printf("Creating linked list with values: 10, 20, 30, 40, 50\n\n");
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printForward(head);
    printReverse(head);
    
    return 0;
}