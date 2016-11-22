// Write code to partition a linked list around a value x,
// such that all nodes less than x come before all nodes
// greater than or equal to x. If x is contained within the list,
// The values of x only need to be after the elements less than x (see below).
// The partition element x can appear anywhere in the "right partition";
// it does not need to appear between the left and right partitions.

#include <stdio.h>
#include "../single.h"

struct node *partition(struct node *head, int x) {
    struct node *high = NULL;
    struct node *last_high = NULL;
    struct node *low = NULL;
    struct node *last_low = NULL;
    while(head != NULL) {
        if(head->value < x) {
            if(low == NULL) {
                low = head;
                last_low = head;
            } else {
                last_low->next = head;
                last_low = head;
            }
        } else {
            if(high == NULL) {
                high = head;
                last_high = head;
            } else {
                last_high->next = head;
                last_high = head;
            }
        }
        head = head->next;
    }
    last_low->next = high;
    return low;
}

int main() {

    struct node *head = malloc(sizeof(struct node));
    head->value = 1;
    head->next = NULL;
    add_item(head, 6);
    add_item(head, 3);
    add_item(head, 2);
    add_item(head, 1);
    add_item(head, 4);

    printf("Before: ");
    print_list(head);

    printf("\nPartitioning with x=3:\n");
    head = partition(head, 3);

    printf("After: ");
    print_list(head);
    printf("\n");

    free_list(head);

    return 0;
}