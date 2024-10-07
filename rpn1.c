#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // Include assert header

//Stack structure definition with typedef
typedef struct stack {
    int value;                //the stack stores integers
    struct stack* next;       // Pointer to the next node
} stack;

// Create a new stack (initializes top as NULL)
stack* create() {
    return NULL;  // Initially, the stack is empty
}

// Push an element onto the stack
stack* push(stack* top, int x) {
    stack* elmt = calloc(1, sizeof(stack));
    assert(elmt != NULL); // Assert memory allocation was successful

    elmt->value = x;
    elmt->next = top;  // make the new node the top
    return elmt;       // Return the new top of the stack
}

// Pop an element from the stack
int pop(stack** p_top) {
    assert(p_top != NULL && *p_top != NULL); // Assert that top is not NULL and stack is not empty

    stack* top = *p_top;  // Pointer to the top node
    int popped = top->value;  // Extracted value
    *p_top = top->next;  // Make the next node the new top node
    free(top);  // Freeing the top node
    return popped;  // Return the popped value
}
 //The pop function takes a pointer to a pointer (stack** top) to allow modification of the original pointer representing the top of the stack.


// Display the stack elements
void display(stack* top) {
    while (top != NULL) {
        printf("%d\n", top->value);
        top = top->next;
    }
}

//Test case
int main() {
    stack* myStack = create();
    myStack = push(myStack, 10);
    myStack = push(myStack, 20);
    myStack = push(myStack, 30);

    printf("Stack elements:\n");
    display(myStack);

    printf("Popped element: %d\n", pop(&myStack));
    printf("Stack after popping:\n");
    display(myStack);

    // Popping remaining elements
    while (myStack != NULL) {
        printf("Popped element: %d\n", pop(&myStack));
    }

    return 0;
}