//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtLast(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    newNode->prev = current;
}
void deleteFromFront(struct Node **head){
    if (*head == NULL) return;
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
}
void deleteFromLast(struct Node **head){
    if (*head == NULL) return;
    struct Node *current = *head;
    while (current->next != NULL) current = current->next;
    if (current->prev != NULL) current->prev->next = NULL;
    else *head = NULL;
    free(current);
}
void deleteGivenNumber(struct Node **head, int data){
    struct Node *current = *head;
    while (current != NULL){
        if (current->data == data){
            if (current->prev != NULL) current->prev->next = current->next;
            else  *head = current->next;
            if (current->next != NULL) current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}
void printList(struct Node *head){
    struct Node *current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(){
    struct Node *head = NULL;
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);
    printf("Original List: ");
    printList(head);
    deleteFromFront(&head);
    printf("After Deleting from Front: ");
    printList(head);
    deleteFromLast(&head);
    printf("After Deleting from Last: ");
    printList(head);
    int numberToDelete = 2;
    deleteGivenNumber(&head, numberToDelete);
    printf("After Deleting %d: ", numberToDelete);
    printList(head);
    return 0;
}
