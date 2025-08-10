#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node into sorted circular linked list
struct Node* insertSorted(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    // Case 1: List is empty
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    struct Node* current = head;
    
    // Case 2: Insert before head (smallest value)
    if (data < head->data) {
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        return newNode;
    }
    
    // Case 3: Insert between two nodes
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) printf("->");
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = head;  // Making it circular
    
    printf("Original list: ");
    printList(head);
    
    int newData;
    printf("Enter data to insert: ");
    scanf("%d", &newData);
    
    head = insertSorted(head, newData);
    
    printf("Modified list: ");
    printList(head);
    
    // Free memory (optional, for completeness)
    struct Node* temp = head;
    if (temp != NULL) {
        struct Node* start = temp;
        do {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        } while (temp != start);
    }
    
    return 0;
}
