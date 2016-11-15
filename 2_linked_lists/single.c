// Implementation of a singly linked list

#include "single.h"

// Get pointer to last node in a singly linked list
struct node *get_last(struct node *head) {
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}

// Append an item to the end of a singly linked list of integers
void add_item(struct node *head, int value) {
	// Create new node and add it to the list
    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;
    get_last(head)->next = new;
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

// Free all nodes in a singly linked list
void free_list(struct node *head) {
	struct node *tmp;
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(head);
}