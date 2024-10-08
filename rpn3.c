#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_integer(char *str);
int is_arithmetic_operator(const char *str);

//test case
int main(int argc, char* argv[]){
    for(int i = 1; i < argc; i++){
        if(is_integer(argv[i]) ){
            printf("INTEGER : %s\n", argv[i]);
        }
        else{
            if( is_arithmetic_operator(argv[i]) ){
                printf("OPERATOR : %s\n", argv[i]);
            }
            else{
                printf("UNKNOWN : %s\n", argv[i]);
            }
        }
    }
    return 0;
}

// Function to check if a string is an integer (only contains digits)
int is_integer(char *str){
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

// I do not see a practical use of the is_valid_token function
/*
int is_valid_token(char *str) {
    return is_integer(str) || is_arithmetic_operator(str);
}
*/