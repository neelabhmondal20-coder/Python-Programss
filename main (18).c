#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse the doubly linked list
struct Node* reverse(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->ne
