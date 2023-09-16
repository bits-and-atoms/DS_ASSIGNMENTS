//SUBHAM MAJUMDER
//2212020
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
struct Node* newNode(int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
void push(struct Node** head_ref, int new_data){
	struct Node* new_node = newNode(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
long long multiplyTwoLists(Node* first, Node* second){
	long long N = 1000000007;
	long long num1 = 0, num2 = 0;
	while (first || second) {
		if (first) {
			num1 = ((num1)*10) % N + first->data;
			first = first->next;
		}
		if (second) {
			num2 = ((num2)*10) % N + second->data;
			second = second->next;
		}
	}
	return ((num1 % N) * (num2 % N)) % N;
}
void printList(struct Node* node){
	while (node != NULL) {
		printf("%d", node->data);
		if (node->next)
			printf("->");
		node = node->next;
	}
	printf("\n");
}
int main(){
	struct Node* first = NULL;
	struct Node* second = NULL;
	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	printf("First List is: ");
	printList(first);
	push(&second, 4);
	push(&second, 8);
	printf("Second List is: ");
	printList(second);
	printf("Result is: ");
	printf("%lld", multiplyTwoLists(first, second));
	return 0;
}