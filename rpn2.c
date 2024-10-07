#include <stdio.h>
#include <stdlib.h>


// check if a string is an integer or not
int is_integer(char* input) {
    // check if the input is empty
    if(input == ""){
        return 0;
    }

    int i = 0;
    int valid = 1;
    // iterate each character in the input
    while(input[i] != '\0' && valid){
        // check if the character is an integer using ASCII code
        if(input[i] < 48 || input[i] > 57){
            valid = 0;
        }
        i++;
    }
    return valid;
}

//test case
int main() {
    int res = is_integer("4 33");
    printf("%d",res);
    return 0;
}