#include <stdlib.h>
#include <stdio.h>
#include <string.h> // Include for strdup and free
#include "stack.h"
// Authur @Curtis Alves
// Initializes the stack
stack_t *initStack() {
    stack_t *newStack = (stack_t*) malloc(sizeof(stack_t));
    if (newStack == NULL) {
        fprintf(stderr, "Failed to allocate memory for stack\n");
        exit(EXIT_FAILURE);
    }
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

// Pops the top element from the stack
char* pop(stack_t* s) {
    if (s->size > 0) {
        stacknode_t *topNode = s->top;
        char* data = topNode->data; // Assuming data is a char*
        s->top = topNode->next;
        s->size--;
        free(topNode); // Free the node itself, but not the data
        return data;
    }
    return NULL;
}

// Pushes a new element onto the stack
void push(stack_t* s, char* item) {
    stacknode_t *newNode = (stacknode_t*) malloc(sizeof(stacknode_t));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for stack node\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(item); // Duplicate the string to ensure the stack owns its copy
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// Frees the stack and all its elements
void freeStack(stack_t* s) {
    while (s->size > 0) {
        char* data = pop(s);
        free(data); // Now we also free the string data
    }
    free(s); // Finally, free the stack structure itself
}

// Prints the stack contents
void printStack(stack_t* s) {
    stacknode_t *current = s->top;
    while (current != NULL) {
        printf("%s\n", current->data); // Print each path
        current = current->next;
    }
}
