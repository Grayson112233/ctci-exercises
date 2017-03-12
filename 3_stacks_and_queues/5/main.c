// Write a program to sort a stack such that the smallest items are on the top.
// You can use an additional temporary stack, but you may not copy the elements
// into any other data structure (such as an array). The stack supports the
// following operations: push, pop, peek, and isEmpty.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

void stack_push(struct node **head, int value) {
	struct node *new = malloc(sizeof(struct node));
	new->value = value;
	new->next = *head;
	*head = new;
}

int stack_pop(struct node **head) {
	struct node *old = *head;
	int value = old->value;
	*head = old->next;
	free(old);
	return value;
}

int stack_peek(struct node *head) {
	return head->value;
}

bool stack_is_empty(struct node *head) {
	return head == NULL;
}

void stack_sort(struct node **head) {
	struct node *temp = NULL;
	while(!stack_is_empty(*head)) {
		// Hold the first value from the primary stack
		int value = stack_pop(head);
		// If the temp stack holds any values greater than value,
		// replace them back to the primary stack
		while(!stack_is_empty(temp) && stack_peek(temp) > value) {
			stack_push(head, stack_pop(&temp));
		}
		// Place the value into the temp stack
		stack_push(&temp, value);
	}
	while(!stack_is_empty(temp)) {
		stack_push(head, stack_pop(&temp));
	}
}

int main() {
	struct node *head = NULL;
	stack_push(&head, 4);
	stack_push(&head, 2);
	stack_push(&head, 7);
	stack_push(&head, 1);
	stack_sort(&head);
	printf("%d\n", stack_pop(&head));
	printf("%d\n", stack_pop(&head));
	printf("%d\n", stack_pop(&head));
	printf("%d\n", stack_pop(&head));
}