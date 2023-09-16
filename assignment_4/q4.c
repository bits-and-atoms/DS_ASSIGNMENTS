//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void swapPairs(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        int temp_data = current->data;
        current->data = current->next->data;
        current->next->data = temp_data;

        current = current->next->next;
    }
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

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Original linked list: ");
    printList(head);

    swapPairs(&head);

    printf("Linked list after pairwise swapping: ");
    printList(head);

    return 0;
}