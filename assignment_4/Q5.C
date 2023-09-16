//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct Node* reverseKNodes(struct Node* head, int k) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    int count = 0;

    while (count < k && current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (current != NULL) {
        head->next = current;
    }

    count = 0;
    while (count < k - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        current->next = reverseKNodes(current->next, k);
    }

    return prev;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int k;

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original linked list: ");
    printList(head);

    k = 3;

    head = reverseKNodes(head, k);

    printf("Linked list after reversing every alternate %d nodes: ", k);
    printList(head);

    return 0;
}