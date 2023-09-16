//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseLinkedList(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL) {
        
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    
    printf("Original linked list: ");
    printLinkedList(head);

    head = reverseLinkedList(head);

    printf("Reversed linked list: ");
    printLinkedList(head);

    return 0;
}