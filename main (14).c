#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove cycle if present
int removeCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // No cycle found
    if (fast == NULL || fast->next == NULL)
        return 0;

    // Find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node in cycle and break it
    struct Node* temp = slow;
    while (temp->next != slow) {
        temp = temp->next;
    }
    temp->next = NULL;

    return 1;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* posNode = NULL;

    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Store position node if pos matches
        if (i == pos) posNode = newNode;
    }

    scanf("%d", &pos);

    // Create cycle if pos > 0
    if (pos > 0) {
        struct Node* temp = head;
        for (int i = 1; i
