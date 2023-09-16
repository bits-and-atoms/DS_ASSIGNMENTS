//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int findNthFromEnd(struct Node* head, int n) {
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;

    while (count < n) {
        if (ref_ptr == NULL) {

            return -1;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    return main_ptr->data;
}

int main() {
    struct Node* head = NULL;
    int n;

    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);
    insert(&head, 25);

    scanf("%d",&n);
    int result = findNthFromEnd(head, n);

    if (result != -1) {
        printf("The %dth node from the end is %d\n", n, result);
    } else {
        printf("Invalid input. The linked list may have fewer than %d nodes.\n", n);
    }

    return 0;
}