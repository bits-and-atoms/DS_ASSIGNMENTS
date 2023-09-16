//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include<stdlib.h>
struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist Node;
Node* newNode(int data){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
Node* partition(Node* head, int x){
	Node *smallerHead = NULL, *smallerLast = NULL;
	Node *greaterLast = NULL, *greaterHead = NULL;
	Node *equalHead = NULL, *equalLast = NULL;
	while (head != NULL) {
		if (head->data == x) {
			if (equalHead == NULL) equalHead = equalLast = head;
			else {
				equalLast->next = head;
				equalLast = equalLast->next;
			}
		}
		else if (head->data < x) {
			if (smallerHead == NULL) smallerLast = smallerHead = head;
			else {
				smallerLast->next = head;
				smallerLast = head;
			}
		}
		else{
			if (greaterHead == NULL) greaterLast = greaterHead = head;
			else {
				greaterLast->next = head;
				greaterLast = head;
			}
		}
		head = head->next;
	}
	if (greaterLast != NULL) greaterLast->next = NULL;
	if (smallerHead == NULL) {
		if (equalHead == NULL) return greaterHead;
		equalLast->next = greaterHead;
		return equalHead;
	}
	if (equalHead == NULL) {
		smallerLast->next = greaterHead;
		return smallerHead;
	}
	smallerLast->next = equalHead;
	equalLast->next = greaterHead;
	return smallerHead;
}
void printList(Node* head){
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main(){
	Node* head = newNode(10);
	head->next = newNode(4);
	head->next->next = newNode(5);
	head->next->next->next = newNode(30);
	head->next->next->next->next = newNode(2);
	head->next->next->next->next->next = newNode(50);
	int x = 3;
	head = partition(head, x);
	printList(head);
	return 0;
}