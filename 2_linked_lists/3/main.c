// Implement an algorithm to delete a node in the middle
// (i.e., any node but the first and last node,
// not necessarily the exact middle) of a singly linked list,
// given only access to that node.

#include <stdio.h>
#include <stdlib.h>
#include "../single.h"

void remove_middle(struct node *node) {
    while(node->next != NULL) {
        node->value = node->next->value;
        if(node->next->next == NULL) {
            free(node->next);
            node->next = NULL;
        } else {
            node = node->next;
        }
    }
}

int main() {

    struct node *head = malloc(sizeof(struct node));
    head->value = 1;
    head->next = NULL;
    add_item(head, 2);
    add_item(head, 3);
    add_item(head, 4);
    add_item(head, 5);
    add_item(head, 6);

    printf("Before: ");
    print_list(head);
    // Remove the third element
    printf("\nRemoving the 3rd element\n");
    remove_middle(head->next->next);
    printf("After: ");
    print_list(head);
    printf("\n");

    free_list(head);

    return 0;
}