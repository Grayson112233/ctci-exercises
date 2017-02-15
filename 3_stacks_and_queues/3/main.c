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

    // Create new node to insert
    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->next = NULL;

    // Navigate to the last substack
    while(head->next != NULL) {
        head = head->next;
    }

    // Create a new substack if necessary
    if(head->left == 0) {
        struct substack *new_sub = malloc(sizeof(struct substack));
        new_sub->next = NULL;
        new_sub->left = SUBSTACK_SIZE-1;
        new_sub->head = malloc(sizeof(struct node));
        new_sub->head->next = NULL;
        new_sub->head->value = value;
        return;
    }

    struct node *current_node = head->head;
    // Get to the last node of the substack
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = malloc(sizeof(struct node));
    current_node->next->next = NULL;
    current_node->next->value = value;
}

int pop(struct substack *stack) {
    // Get to the last substack
    while(stack->next != NULL) {
        stack = stack->next;
    }
    // Get to the last node of this substack
    struct node *n = stack->head;
    struct node *previous = stack->head;
    while(n->next != NULL) {
        previous = n;
        n = n->next;
    }
    int value = n->value;
    free(n);
    previous->next = NULL;
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

    printf("Pop: %d\n", pop(head));
    printf("Pop: %d\n", pop(head));
    printf("Pop: %d\n", pop(head));
    printf("Pop: %d\n", pop(head));
    printf("Pop: %d\n", pop(head));

    return 0;

}
