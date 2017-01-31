// Stack of Plates: Implement a standard stack with several substacks of a maximum size

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUBSTACK_SIZE 3

struct node {
    int value;
    struct node *next;
};

struct substack {
    struct node *head;
    struct substack *next;
    int left;
};

// Create a new stack with initial value
struct substack *init_stack(int value) {
    struct substack *head = malloc(sizeof(struct substack));
    head->head = malloc(sizeof(struct node));
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
            printf("Current stack has room\n");
            // If there is room:
            // Get to the last node in the list and create a
            // new node after it.
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
            printf("Current stack doesn't have room, creating new one.\n");
            // If there is no more room:
            // Create a new substack and set its first node with value
            if(head->next == NULL) {
                struct substack *n = head->next;
                n = malloc(sizeof(struct substack));
                n->next = NULL;
                n->left = SUBSTACK_SIZE-1;
                n->head = malloc(sizeof(struct node));
                n->head->value = value;
                n->head->next = NULL;
            }
            return;
        }
    }
}

int pop(struct substack *stack) {
    // Get to the last substack
    while(stack->next != NULL) {
        stack = stack->next;
    }
    // Get to the last node of this substack
    struct node *n = stack->head;
    while(n->next != NULL) {
        n = n->next;
    }
    int value = n->value;
    free(n);
    n = NULL;
    stack->left += 1;
    // If we just freed the last node in a substack, free
    // that substack as well
    if(stack->left == SUBSTACK_SIZE) {
        free(stack);
        stack = NULL;
    }
    return value;
}

int main() {

    printf("Initializing with 1\n");
    struct substack *head = init_stack(1);
    push(head, 2);
    printf("Pushing 2\n");
    push(head, 3);
    printf("Pushing 3\n");
    push(head, 4);
    printf("Pushing 4\n");
    push(head, 5);
    printf("Pushing 5\n");

    printf("Pop: %d", pop(head));
    printf("Pop: %d", pop(head));
    

    return 0;

}
