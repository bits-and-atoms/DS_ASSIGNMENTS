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

void printMiddle(struct Node* head) {
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        printf("The middle element is %d\n", slow_ptr->data);
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

    push(&head, 5);
    push(&head, 45);
    push(&head, 356);
    push(&head, 25);
    push(&head, 53);

    printf("Original linked list: ");
    printList(head);

    printMiddle(head);

    return 0;
}