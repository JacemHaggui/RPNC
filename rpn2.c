#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is an integer (only contains digits)
int is_integer(char *str) {
    // Check if the string is empty
    if (*str == '\0') {
        return 0; // Not an integer
    }

    // Check each character to see if it's a digit
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is between '0' and '9'
        if (str[i] < '0' || str[i] > '9') { //chars are ASCII values
            return 0; // Found a non-digit character
        }
    }
    return 1; // String contains only digits
}

//check if a string is an arithmetic operator
int is_arithmetic_operator(const char *str) {
    // Check if the string length is 1 and it is one of the operators
    return (strlen(str) == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
}

// Function to check if a string is a valid token (integer or operator)
int is_valid_token(char *str) {
    return is_integer(str) || is_arithmetic_operator(str);
}

//test case
int main() {
    int res1 = is_valid_token("433");
    int res2 = is_valid_token("*");
    printf("%d",res2);
    return 0;
}