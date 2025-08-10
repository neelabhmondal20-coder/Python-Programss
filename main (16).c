#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Utility: reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Remove leading zeros
struct Node* removeLeadingZeros(struct Node* head) {
    while (head && head->data == 0 && head->next != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Add two reversed lists
struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node* tail = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }

        carry = sum / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    return dummy.next;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;
    scanf("%d", &n1);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &n2);
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Step 1: Remove leading zeros
    head1 = removeLeadingZeros(head1);
    head2 = removeLeadingZeros(head2);

    // Step 2: Reverse both lists
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    // Step 3: Add them
    struct Node* sumList = addTwoLists(head1, head2);

    // Step 4: Reverse result to original order
    sumList = reverseList(sumList);

    // Step 5: Print
    printList(sumList);

    return 0;
}
