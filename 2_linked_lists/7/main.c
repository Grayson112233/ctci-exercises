#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../single.h"

struct node *get_last(struct node *n) {
	while(n->next != NULL) {
		n = n->next;
	}
	return n;
}

bool has_intersection(struct node *l1, struct node *l2) {
	return get_last(l1) == get_last(l2);
}

int main() {

	// Create the first list, with numbers 1-5
	struct node *l1 = malloc(sizeof(struct node));
    l1->value = 1;
    l1->next = NULL;
    add_item(l1, 2);
    add_item(l1, 3);
    add_item(l1, 4);
    add_item(l1, 5);

    // Create a second list which intersects with l1's 4th node
    struct node *l2 = malloc(sizeof(struct node));
    l2->value = 6;
    l2->next = NULL;
    add_item(l2, 7);
    add_item(l2, 8);
    l2->next->next->next = l1->next->next->next;

    printf("List 1: ");
    print_list(l1);
    printf("\nList 2: ");
    print_list(l2);
    printf("\n");

    free_list(l1);
    free_list(l2);
}