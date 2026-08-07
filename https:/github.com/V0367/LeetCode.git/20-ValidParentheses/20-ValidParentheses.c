// Last updated: 07/08/2026, 15:40:42
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = 0;
    char* stack = (char*)malloc(strlen(s) * sizeof(char));

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[len++] = s[i]; // Push opening bracket to stack
        } else {
            if (len == 0) {
                free(stack);
                return false; // No corresponding opening bracket
            }
            if ((s[i] == ')' && stack[len - 1] != '(') || 
                (s[i] == '}' && stack[len - 1] != '{') || 
                (s[i] == ']' && stack[len - 1] != '[')) {
                free(stack);
                return false; // Bracket mismatch
            }
            len--; // Pop the stack
        }
    }

    free(stack);
    return len == 0; // If stack is empty, brackets are balanced
}
