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

void deleteKey(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;

    while (current != NULL) {
        
        if (current->data == key) {

            if (prev == NULL) {
                *head_ref = current->next;
                free(current);
                current = *head_ref;
            } else {

                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
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
    int key;

    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    push(&head, 2);

    printf("Original linked list: ");
    printList(head);

    key = 2;

    deleteKey(&head, key);

    printf("Linked list after deleting all occurrences of %d: ", key);
    printList(head);

    return 0;
}