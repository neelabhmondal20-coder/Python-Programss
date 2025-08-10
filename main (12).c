#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int kthFromEnd(struct Node* head, int k) {
    struct Node *fast = head, *slow = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) return -1; // k > length
        fast = fast->next;
    }

    // Move both pointers until fast reaches end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow ? slow->data : -1;
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
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
    }

    scanf("%d", &k);

    int result = kthFromEnd(head, k);
    printf("%d\n", result);

    return 0;
}
