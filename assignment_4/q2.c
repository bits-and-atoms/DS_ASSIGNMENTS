//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseBetween(struct Node* head, int m, int n) {
    if (m == n || head == NULL || head->next == NULL) {
        return head;
    }

    struct Node dummy; 
    dummy.next = head;
    struct Node* prevM = &dummy;
    struct Node* currM;
    struct Node* prev = NULL;
    struct Node* curr = head;
    int position = 1;

    while (position < m) {
        prevM = prevM->next;
        curr = curr->next;
        position++;
    }
    currM = curr;

    while (position <= n) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        position++;
    }

    prevM->next = prev;
    currM->next = curr;

    return dummy.next;
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
    head = insert(head, 5);

    printf("Original linked list: ");
    printLinkedList(head);

    int m = 2; 
    int n = 4; 

    head = reverseBetween(head, m, n);

    printf("Reversed linked list from position %d to %d: ", m, n);
    printLinkedList(head);

    return 0;
}