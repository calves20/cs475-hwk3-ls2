#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
// Authur @Curtis Alves
// Defines the node structure for the stack
typedef struct stacknode_t {
    char* data; // Holds a pointer to the string data
    struct stacknode_t* next; // Points to the next node in the stack
} stacknode_t;

// Defines the structure for the stack itself
typedef struct stack_t {
    stacknode_t* top; // Points to the top node in the stack
    int size; // Tracks the number of items in the stack
} stack_t;

// Function prototypes
stack_t* initStack(); 
char* pop(stack_t* s); 
void push(stack_t* s, char* item);
void freeStack(stack_t* s); 
void printStack(stack_t* s);

#endif // STACK_H_INCLUDED
