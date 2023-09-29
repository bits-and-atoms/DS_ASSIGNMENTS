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

void insertAtFront(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
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

void insertAfterNode(struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL.");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void insertBeforeNode(struct Node **head, struct Node *nextNode, int data)
{
    if (nextNode == NULL)
    {
        printf("Next node cannot be NULL.");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }
    nextNode->prev = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtFront(&head, 1);
    insertAtFront(&head, 2);
    insertAtFront(&head, 3);

    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    struct Node *nodeToInsertAfter = head->next;
    insertAfterNode(nodeToInsertAfter, 6);

    struct Node *nodeToInsertBefore = head->next->next->next;
    insertBeforeNode(&head, nodeToInsertBefore, 7);

    printList(head);

    return 0;
}
