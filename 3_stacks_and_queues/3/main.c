// Stack of Plates: Implement a standard stack with several substacks of a maximum size

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUBSTACK_SIZE 3

struct node {
    int value;
    struct node *next;
}

struct substack {
    struct node *head;
    struct substack *next;
    int left;
}

struct substack *init_stack(int value) {
    substack *head = malloc(sizeof(struct substack));
    head->head = malloc(sizeof(node));
    head->head->value = value;
    head->head->next = NULL;
    head->next = NULL;
    head->left = SUBSTACK_SIZE;
    return head;
}

void push(struct substack *head, int value) {
    while(true) {
        // Check if current substack has room
        if(head->left > 0) {
            struct node *n = head->head;
            if(n == NULL) {
                n = malloc(sizeof(struct node));
            } else {
                while(n->next != NULL) {
                    n = n->next;
                }
                n->next = malloc(sizeof(struct node));
                n = n->next;
            }
            n->value = value;
            n->next = NULL;
            head->left -= 1;
            return;
        } else {
            if(head->next = NULL) {
                head->next = malloc(sizeof(struct substack));
                head->next->next = NULL;
                head->next->left = SUBSTACK_SIZE;
                head->next->head = NULL;
            head = head->next;
        }
    }
}

int main() {

    struct substack *head = init_stack(1);
    

    return 0;

}
