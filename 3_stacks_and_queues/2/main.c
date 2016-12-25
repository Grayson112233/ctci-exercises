// How would you design a stack which, in addition to push and pop, has a
// function min which returns the minimum element? Push, pop and min should
// all operate in 0(1) time.

#include <stdio.h>
#include <stdlib.h>

// Stack node
struct node {
	int value;
	int min;
	struct node *next;
};

// Creates first node in this stack
struct node *init_stack(int value) {
	struct node *head = malloc(sizeof(head));
	head->value = value;
	head->min = value;
	head->next = NULL;
	return head;
}

void push(struct node **head, int value) {
	struct node *new = malloc(sizeof(struct node));
	new->value = value;
	new->min = value < (*head)->min ? value : (*head)->min;
	new->next = *head;
	*head = new;
}

int get_min(struct node *head) {
	return head->min;
}

int pop(struct node **head) {
	struct node *new_head = (*head)->next;
	int value = (*head)->value;
	free(*head);
	*head = new_head;
	return value;
}

int main() {


	struct node *head = init_stack(3);
	push(&head, 2);
	push(&head, 4);
	printf("Minimum is %d\n", get_min(head));
	printf("Popped %d and %d\n", pop(&head), pop(&head));
	printf("Minimum is %d\n", get_min(head));

}