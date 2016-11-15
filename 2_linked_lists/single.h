#include <stdio.h>
#include <stdlib.h>

// Node for a singly linked list of integers
struct node {
	int value;
	struct node *next;
};

struct node *get_last(struct node *head);
void add_item(struct node *head, int value);
void print_list(struct node *head);
void free_list(struct node *head);