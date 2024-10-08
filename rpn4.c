#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // Include assert header
#include <string.h>

// The help message
const char *manuel = "This is the help message";

// Stack structure definition with typedef
typedef struct stack {
    int value;                // The stack stores integers
    struct stack* next;       // Pointer to the next node
} stack;

//----------------------------------------------------------------------------------------
// Function declarations
stack* create();                        // Create a new stack
stack* push(stack* top, int x);        // Push an element onto the stack
int pop(stack** p_top);                 // Pop an element from the stack
void display(stack* top);               // Display stack elements

int is_integer(char *str);              // Check if a string is an integer
int is_arithmetic_operator(const char *str); // Check if a string is an arithmetic operator
int is_valid_token(char *str);          // Check if a string is a valid token

// Apply an arithmetic operation on two integers
int apply_operation(int a, int b, char* op);
//----------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
    // Checking if user asked for help
    if ((argc == 1) || (argc == 2 && (strcmp(argv[1], "-h") || strcmp(argv[1], "--help")))) {
        printf("%s\n", manuel);
        return 0;
    }
    
    stack* stack = create();            // Create an empty stack
    // Process each argument
    for (int i = 1; i < argc; i++) {
        if (is_valid_token(argv[i])) {  // Check if the token is valid
            if (is_arithmetic_operator(argv[i])) { // If token is an operator
                // Checking if stack is empty before popping two elements
                if (stack == NULL) {
                    printf("ERROR\n");
                    return 1;  // Return an error code
                }
                int a = pop(&stack);  // Pop the first operand
                if (stack == NULL) {
                    printf("ERROR\n");
                    return 1;  // Return an error code
                }
                int b = pop(&stack);  // Pop the second operand
                int res = apply_operation(b, a, argv[i]); // Apply the operation
                stack = push(stack, res); // Push the result back onto the stack
            }
            if (is_integer(argv[i])) {  // If token is an integer
                int res = atoi(argv[i]); // Convert string to integer
                stack = push(stack, res); // Push the integer onto the stack
            }
        } else {
            printf("ERROR: Invalid token\n");
            printf("The character is: %s\n", argv[i]);
            display(stack);              // Display the current stack
            return 0;                    // Exit program on error
        }
    }
    
    int result = pop(&stack);            // Pop the final result
    if (stack != NULL) {                 // Check if stack is empty
        printf("ERROR\n");
        return 1;                        // Exit program on error
    }

    printf("RESULT : %d\n", result);     // Print the final result
    return 0;                            // Successful exit
}

//----------------------------------------------------------------------------------------

// Function definitions

// Create a new stack (initializes top as NULL)
stack* create() {
    return NULL;  // Initially, the stack is empty
}

// Push an element onto the stack
stack* push(stack* top, int x) {
    stack* elmt = calloc(1, sizeof(stack)); // Allocate memory for a new element
    assert(elmt != NULL); // Assert memory allocation was successful

    elmt->value = x;      // Set the value of the new element
    elmt->next = top;     // Make the new element the top of the stack
    return elmt;         // Return the new top of the stack
}

// Pop an element from the stack
int pop(stack** p_top) {
    assert(p_top != NULL && *p_top != NULL); // Assert that top is not NULL and stack is not empty

    stack* top = *p_top;  // Pointer to the top node
    int popped = top->value;  // Extracted value
    *p_top = top->next;  // Make the next node the new top node
    free(top);  // Free the top node
    return popped;  // Return the popped value
}

// Display the stack elements
void display(stack* top) {
    while (top != NULL) {
        printf("%d\n", top->value);  // Print the value of the current node
        top = top->next;              // Move to the next node
    }
}

// Function to check if a string is an integer (only contains digits)
int is_integer(char *str) {
    // Check if the string is empty
    if (*str == '\0') {
        return 0; // Not an integer
    }

    // Check each character to see if it's a digit
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is between '0' and '9'
        if (str[i] < '0' || str[i] > '9') { // chars are ASCII values
            return 0; // Found a non-digit character
        }
    }
    return 1; // String contains only digits
}

// Check if a string is an arithmetic operator
int is_arithmetic_operator(const char *str) {
    // Check if the string length is 1 and it is one of the operators
    return (strlen(str) == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
}

// Function to check if a string is a valid token (integer or operator)
int is_valid_token(char *str) {
    return is_integer(str) || is_arithmetic_operator(str); // Valid if it's an integer or operator
}

// Apply an arithmetic operation on two integers
int apply_operation(int a, int b, char* op) {
    switch (op[0]) {
        case '+':
            return a + b;              // Addition
        case '-':
            return a - b;              // Subtraction
        case '*':
            return a * b;              // Multiplication
        case '/':
            if (b != 0) {              // Prevent division by zero
                return a / b;          // Division
            } else {
                printf("Error: Division by zero.\n");
                return 1;              // Exit with error code
            }
        default:
            printf("Error: Invalid operator '%c'.\n", op[0]);
            return 1;                  // Exit with error code
    }
}