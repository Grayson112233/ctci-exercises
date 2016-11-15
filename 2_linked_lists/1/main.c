// Write code to remove duplicates from an unsorted linked list.

#include <stdio.h>
#include <stdlib.h>
#include "../single.h"

void remove_duplicates(struct node *head) {
	struct node *i = head;
	// Traverse list
	while(i != NULL) {
		struct node *j = head;
		struct node *prev = j;
		// Traverse list for duplicates of this node
		while(j != NULL) {
			if(j->value == i->value && j != i) {
				// Remove this duplicate
				prev->next = j->next;
				free(j);
				j = prev->next;
			} else {
				prev = j;
				j = j->next;
			}
		}
		i = i->next;
	}
}

int main() {

	struct node *head = malloc(sizeof(struct node));
	head->value = 1;
	head->next = NULL;
	add_item(head, 1);
	add_item(head, 2);
	add_item(head, 3);
	add_item(head, 4);
	add_item(head, 3);
	add_item(head, 5);
	add_item(head, 6);
	//add_item(head, 6);

	printf("Before: \n");
	print_list(head);
	printf("\n");

	remove_duplicates(head);

	printf("After:  \n");
	print_list(head);
	printf("\n");

	free_list(head);

	return 0;
}
