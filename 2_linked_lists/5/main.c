// You have two numbers represented by a linked list,
// where each node contains a single digit. The digits
// are stored in reverse order, such that the 1 's digit
// is at the head of the list. Write a function that adds
// the two numbers and returns the sum as a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../single.h"

int list_digits_sum(struct node *head) {
    int num = 0, i = 0;
    while(head != NULL) {
        num += head->value * pow(10, i);
        head = head->next;
        i++;
    }
    return num;
}

int main() {

    struct node *l1 = malloc(sizeof(struct node));
    l1->value = 1;
    l1->next = NULL;
    add_item(l1, 6);
    add_item(l1, 3);

    struct node *l2 = malloc(sizeof(struct node));
    l2->value = 1;
    l2->next = NULL;
    add_item(l2, 2);
    add_item(l2, 1);

    printf("List 1: ");
    print_list(l1);
    printf(" = %d\n", list_digits_sum(l1));
    printf("List 2: ");
    print_list(l2);
    printf(" = %d\n", list_digits_sum(l2));

    printf("Sum is %d\n", list_digits_sum(l1) + list_digits_sum(l2));

    free_list(l1);
    free_list(l2);
}