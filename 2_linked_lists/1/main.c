// Write code to remove duplicates from an unsorted linked list.

#include <stdio.h>
#include <stdlib.h>
#include "../single.h"

int main() {

	struct node *head = malloc(sizeof(struct node));
	head->value = 1;
	head->next = NULL;
	add_item(head, 2);
	add_item(head, 3);

	print_list(head);
	printf("\n");

	free_list(head);

	return 0;
}
