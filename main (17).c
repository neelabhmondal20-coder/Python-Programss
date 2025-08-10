#include <stdio.h>
#include <stdlib.h>

// Structure for a node in doubly linked list
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

// Function to delete node at a given position (1-based index)
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) return head;

    struct Node* temp = head;
    int i;

    // If head needs to be deleted
    if (position == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
