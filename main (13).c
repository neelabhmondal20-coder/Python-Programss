#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Detect loop using Floyd's cycle detection
bool detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* loopNode = NULL;

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
        if (i == pos) loopNode = newNode; // store position node
    }

    scanf("%d", &pos);

    // Create loop if pos > 0
    if (pos > 0) {
        struct Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp;
    }

    if (detectLoop(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
