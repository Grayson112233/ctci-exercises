// Write code to remove duplicates from an unsorted linked list.

#include <stdio.h>
#include <stdlib.h>

// Node for a singly linked list of integers
struct node {
	int value;
	struct node *next;
}

// Append an item to the end of a singly linked list of integers
void add_item(struct node *head, int value) {
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = malloc(sizeof(struct node));
	head->next->next = NULL;
	head->next->value = value
}

// Print all items from a singly linked list of integers
void print_list(struct node *head) {
	printf("{ ");
	while(head->next != NULL) {
		printf("%d, ", head->value);
		head = head->next;
	}
	printf("%d }", head->value);
}

int main() {

	struct node *head = malloc(sizeof(struct node));
	head = {1, NULL};
	add_item(head, 2);
	add_item(head, 3);

	print_list(head);

	return 0;
}