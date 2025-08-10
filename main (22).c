#include <stdio.h>
#include <stdlib.h>

// Definition for a node in the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->bottom = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* a, struct Node* b) {
    // If either list is empty, return the other list
    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    // Start with the list with the smaller data
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL; // Ensure next pointer is NULL for the merged list
    return result;
}

// Function to flatten the linked list
struct Node* flatten(struct Node* root) {
    if (!root || !root->next) return root;

    // Recursively flatten the next list
    root->next = flatten(root->next);

    // Merge the current list with the flattened next list
    root = merge(root, root->next);

    return root;
}

// Function to print the flattened linked list
void printList(struct Node* node) {
    while (node) {
        printf("%d", node->data);
        if (node->bottom) {
            printf("->");
        }
        node = node->bottom;
    }
    printf("\n");
}

// Main function to demonstrate the flattening of the linked list
int main() {
    // Creating a sample linked list
    struct Node* head = createNode(5);
    head->next = createNode(10);
    head->next->next = createNode(19);
    head->next->next->next = createNode(28);

    head->bottom = createNode(7);
    head->bottom->bottom = createNode(8);
    head->bottom->bottom->bottom = createNode(30);

    head->next->bottom = createNode(20);

    head->next->next->bottom = createNode(22);
    head->next->next->bottom->bottom = createNode(35);
    head->next->next->bottom->bottom->bottom = createNode(40);

    head->next->next->next->bottom = createNode(45);
    head->next->next->next->bottom->bottom = createNode(50);

    printf("Original linked list:\n");
    printList(head);

    // Flatten the linked list
    struct Node* flattenedList = flatten(head);

    printf("Flattened linked list:\n");
    printList(flattenedList);

    // Free memory (optional, for completeness)
    // Note: Memory cleanup is not shown here for simplicity

    return 0;
}
