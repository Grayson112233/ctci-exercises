// Animal Shelter

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DOG 1
#define CAT 2

// Linked List Node (represents a dog or cat)
struct node {
	int type;
	char *name;
	struct node *next;
};

// Not a public interface, only for use by list_enqueue
struct node *create_head(int type, char *name) {
	struct node *head = malloc(sizeof(struct node));
	head->type = type;
	head->name = malloc((strlen(name) + 1) * sizeof(char));
	strcpy(head->name, name);
	head->next = NULL;
}

void list_enqueue(struct node **head, int type, char *name) {
	// Check to see if list is empty
	if(*head == NULL) {
		*head = create_head(type, name);
		return;
	}
	// Otherwise, add a new node at the end of the list
	struct node *temp = *head;
	// Navigate to the end of the list
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Create the new node
	struct node *new = malloc(sizeof(struct node));
	new->type = type;
	new->name = malloc((strlen(name) + 1) * sizeof(char));
	strcpy((*head)->name, name);
	new->next = NULL;
}

// Returns the node of the animal being dequeued
// Type can be specified or 0 for any type
struct node list_dequeue(struct node **head, int type) {
	struct node oldest;
	oldest.type = -1;
	oldest.name = NULL;
	oldest.next = NULL;
	if(type == 0) {
		oldest.type = (*head)->type;
		oldest.name = malloc(sizeof(strlen((*head)->name) + 1) * sizeof(char));
		strcpy(oldest.name, (*head)->name);
		oldest.next = NULL;
		struct node *temp = (*head)->next;
		free(*head);
		*head = temp;
		return oldest;
	} else {
		struct node *prev = NULL;
		struct node *temp = *head;
		while(temp->next != NULL && temp->type != type) {
			prev = temp;
			temp = temp->next;
		}
		// If the type does not match the requested type, then there are no animals
		// of that type avaiable in the queue.
		if(temp->type != type) { return oldest; }
		// Otherwise, return that animal
		oldest.type = temp->type;
		oldest.name = malloc((strlen(temp->name) + 1) * sizeof(char));
		strcpy(oldest.name, temp->name);
		oldest.next = NULL;
		// If we are dequeueing the head
		if(prev == NULL) {
			temp = *head;
			*head = (*head)->next;
			free(temp);
			return oldest;
		} else {
			prev->next = temp->next;
			free(temp);
			return oldest;
		}
	}
}

int main() {
	printf("Enqeueing dog: Lassie\n");
	struct node *head = NULL;
	list_enqueue(&head, DOG, "Lassie");
	printf("Dequeueing cat: ");
	struct node any = list_dequeue(&head, CAT);
	printf("(%s, %d)\n", any.name, any.type);

	return 0;
}
