#include <stdio.h>
#include <stdbool.h>

int transition(int state, char input) {
    switch (state) {
        case 0:
            return (input == '0') ? 1 : 4;
        case 1:
            return (input == '0') ? 1 : (input == '1') ? 2 : 4;
        case 2:
            return (input == '0') ? 1 : (input == '1') ? 3 : 4;
        case 3:
            return (input == '0' || input == '1') ? 3 : 4;
        default:
            return 4; 
    }
}


bool accept(char *input_string) {
    int current_state = 0; 
    char *ptr = input_string;
    

    while (*ptr != '\0') {
        current_state = transition(current_state, *ptr);
        ptr++;
    }
    

    return current_state == 3;
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);
    

    if (accept(input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    
    return 0;
}
