// How would you design a stack which, in addition to push and pop, has a
// function min which returns the minimum element? Push, pop and min should
// all operate in 0(1) time.

#include <stdio.h>
#include <stdlib.h>

// Stack node
struct node {
    int value;
    int min;
    struct node *next;
};

void push(struct node **head, int value) {
    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->min = value < (*head)->min ? value : (*head)->min;
    new->next = *head;
    *head = new;
}

int pop(struct node **head) {
    struct node *old = *head;
    int value = old->value;
    *head = (*head)->next;
    free(old);
    return value;
}

int min(struct node *head) {
    return head->min;
}

int main() {

    struct node *head = malloc(sizeof(head));
    head->value =2;
    head->min = 2;
    head->next = NULL;

    push(&head, 6);
    printf("Pushed 6, min is %d\n", min(head));
    push(&head, 3);
    printf("Pushed 3, min is %d\n", min(head));
    push(&head, 1);
    printf("Pushed 1, min is %d\n", min(head));
    push(&head, 5);
    printf("Pushed 5, min is %d\n", min(head));
    
    printf("Popping returned %d\n.", pop(&head));
}
