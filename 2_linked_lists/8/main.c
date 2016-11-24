// Given a circular linked list, implement an algorithm that
// returns the node at the beginning of the loop.

#include <stdio.h>
#include <stdlib.h>
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

struct node *detect_loop(struct node *head) {
    struct node *temp = head;
    int i = 0;
    while(temp != NULL) {
        struct node *temp2 = head;
        for(int j = 0; j < i; j++) {
            if(temp2 == temp) {
                return temp;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        i++;
    }
    return NULL;
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

    // Set last node (node #6) to point to the 3rd node, creating a loop
    get(head, 5)->next = get(head, 2);

    printf("Evaluating loop node...\n");
    struct node *loop_start = detect_loop(head);
    if(loop_start == NULL) {
        printf("No loop detected.\n");
    } else {
        printf("Loop on element where value = %d\n", loop_start->value);
    }

    // TODO: Free the memory from this program

    return 0;
}