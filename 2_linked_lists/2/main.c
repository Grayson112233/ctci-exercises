// Implement an algorithm to find the kth to last
// element of a singly linked list.

#include <stdio.h>
#include <stdlib.h>
#include "../single.h"

// Assumes a list with at least one node
int get(struct node *head, int index) {
    int i = 0;
    while(head != NULL) {
        if(i == index) {
            return head->value;
        }
        head = head->next;
        i++;
    }
}

int get_length(struct node *head) {
    int length = 0;
    while(head != NULL) {
        head = head->next;
        length ++;
    }
    return length;
}

// Assumes a positive integer k > 0 and <= length
int kth_to_last(struct node *head, int k) {
    return get(head, get_length(head) - k);
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

    printf("List:\n");
    print_list(head);

    printf("\n2nd to last: %d\n", kth_to_last(head, 2));
    printf("1st to last: %d\n", kth_to_last(head, 1));
    printf("6th to last: %d\n", kth_to_last(head, 6));

    free_list(head);

    return 0;
}
