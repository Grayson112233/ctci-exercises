// Implement a function to check if a linked list is a palindrome.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../single.h"

struct node *get(struct node *head, int index) {
    int i = 0;
    while(head != NULL) {
        if(i == index) {
            return head;
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

bool is_palindrome(struct node *head) {
    int length = get_length(head);
    int end[length/2 - length%2];
    struct node *second = get(head, length/2 + length%2);
    int i = 0;
    while(second != NULL) {
        end[i] = second->value;
        i++;
        second = second->next;
    }
    for(int i = length/2 - length%2; i > 0; i--) {
        if(head->value != end[i]) {
            return false;
        }
        head = head->next;
    }

    return true;
}

int main() {

    struct node *head1 = malloc(sizeof(struct node));
    head1->value = 1;
    head1->next = NULL;
    add_item(head1, 2);
    add_item(head1, 3);
    add_item(head1, 4);

    struct node *head2 = malloc(sizeof(struct node));
    head2->value = 5;
    head2->next = NULL;
    add_item(head2, 3);
    add_item(head2, 1);
    add_item(head2, 3);
    add_item(head2, 5);

    printf("List 1: ");
    print_list(head1);
    printf("\nPalindrome: %s\n", is_palindrome(head1) ? "true" : "false");

    printf("List 2: ");
    print_list(head2);
    printf("\nPalindrome: %s\n", is_palindrome(head2) ? "true" : "false");

    free_list(head1);
}