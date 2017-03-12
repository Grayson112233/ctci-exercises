// Implement a MyQueue class which implements a queue using two stacks

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct queue {
	struct node *new_values;
	struct node *reversed;
};

struct queue *create_queue() {
	struct queue *new = malloc(sizeof(struct queue));
	new->new_values = NULL;
	new->reversed = NULL;
	return new;
}

void queue_add(struct queue *queue, int value) {
	struct node *new = malloc(sizeof(struct node));
	new->value = value;
	new->next = queue->new_values;
	queue->new_values = new;
}

int queue_remove(struct queue *queue) {
	while(queue->new_values != NULL) {
		// Create new node on reversed stack
		struct node *new = malloc(sizeof(struct node));
		new->value = queue->new_values->value;
		new->next = queue->reversed;
		queue->reversed = new;
		// Remove old node on new_values stack
		struct node *old = queue->new_values;
		queue->new_values = old->next;
		free(old);
	}
	// pop and return value from reversed stack
	int result = queue->reversed->value;
	struct node *old = queue->reversed;
	queue->reversed = old->next;
	free(old);
	return result;
}

int main() {

	struct queue *q = create_queue();
	printf("Adding 3\n");
	queue_add(q, 3);
	printf("Adding 2\n");
	queue_add(q, 2);
	printf("Adding 1\n");
	queue_add(q, 1);
	printf("Popping\n");
	printf("%d\n", queue_remove(q));
	printf("Popping\n");
	printf("%d\n", queue_remove(q));
	printf("Popping\n");
	printf("%d\n", queue_remove(q));

	//printf("%d\n", queue_remove(q));

	return 0;
}