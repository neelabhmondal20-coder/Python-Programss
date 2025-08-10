#include <stdio.h>
#include <stdlib.h>

// Definition for a node in the linked list
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

// Function to find the intersection point of two linked lists
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (!head1 || !head2) return NULL;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Traverse both lists
    while (ptr1 != ptr2) {
        // Move to the next node or switch to the other list
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    // Either both pointers are NULL (no intersection) or they meet at the intersection point
    return ptr1;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the intersection finding
int main() {
    // Creating first linked list: 4 -> 1 -> 8 -> 4 -> 5
    struct Node* head1 = createNode(4);
    head1->next = createNode(1);
    head1->next->next = createNode(8);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    // Creating second linked list: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    struct Node* head2 = createNode(5);
    head2->next = createNode(6);
    head2->next->next = createNode(1);
    head2->next->next->next = head1->next->next; // 8 -> 4 -> 5 (intersection)

    // Finding the intersection node
    struct Node* intersectionNode = getIntersectionNode(head1, head2);

    if (intersectionNode) {
        printf("The intersection point is: %d\n", intersectionNode->data);
    } else {
        printf("No intersection point found.\n");
    }

    // Free memory (optional, for completeness)
    // Note: Memory cleanup is not shown here for simplicity

    return 0;
}
