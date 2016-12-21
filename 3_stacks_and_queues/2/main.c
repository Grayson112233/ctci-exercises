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

void push(struct node **head, int value) {
	struct node *new = malloc(sizeof(struct node));
	new->value = value;
	new->min = value < min ? value : min;
	new->next = *head;
	*head = new;
}

int main() {

	struct node *head = malloc(sizeof(head));
	// WIP

}