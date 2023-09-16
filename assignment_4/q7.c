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

int countOccurrences(struct Node* head, int target) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }

    return count;
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
    int target, occurrences;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    push(&head, 2);

    printf("Original linked list: ");
    printList(head);

    target = 2;

    occurrences = countOccurrences(head, target);

    printf("The integer %d occurs %d times in the linked list.\n", target, occurrences);

    return 0;
}