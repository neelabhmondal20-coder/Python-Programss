#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete x-th node (1-based indexing)
struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

    // If deleting head
    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = head;
    for (int i = 1; i < x - 1 && prev != NULL; i++) {
        prev = prev->next;
    }

    if (prev != NULL && prev->next != NULL) {
        struct Node* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }

    return head;
}


