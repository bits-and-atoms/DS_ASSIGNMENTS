//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtLast(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseDoublyLinkedList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    struct Node *head = NULL;

    insertAtLast(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    printf("Original List: ");
    printList(head);

    reverseDoublyLinkedList(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
