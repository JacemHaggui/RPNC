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
    stack* elmt = (stack*)malloc(sizeof(stack));
    assert(elmt != NULL); // Assert memory allocation was successful

    elmt->value = x;
    elmt->next = top;  // make the new node the top
    return elmt;       // Return the new top of the stack
}

// Pop an element from the stack
int pop(stack** top) {
    assert(top != NULL && *top != NULL); // Assert that top is not NULL and stack is not empty

    stack* p = *top;  // Pointer to the top node
    int popped = p->value;  // Extracted value
    *top = p->next;  // Make the next node the new top node
    free(p);  // Freeing the top node
    return popped;  // Return the popped value
}
 //The pop function takes a pointer to a pointer (stack** top) to allow modification of the original pointer representing the top of the stack.


// Display the stack elements
void display(stack* top) {
    stack* ptrav = top;  // Pointer to traverse the linked list
    while (ptrav != NULL) {
        printf("%d\n", ptrav->value);
        ptrav = ptrav->next;
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