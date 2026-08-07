// Last updated: 07/08/2026, 15:39:39
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDuplicates(char* s, int k) {
    int len = strlen(s);
    // Stack to hold pairs of (char, count)
    char stack[len];
    int count[len];  // Array to store counts corresponding to each character in the stack
    int top = -1;    // Stack pointer
    
    for (int i = 0; i < len; i++) {
        char ch = s[i];
        
        // If stack is not empty and top character is same as current character
        if (top >= 0 && stack[top] == ch) {
            count[top]++;  // Increment the count of the top element
            if (count[top] == k) {
                top--;  // Remove the top element if count reaches k
            }
        } else {
            top++;
            stack[top] = ch;  // Push the new character
            count[top] = 1;    // Initialize its count to 1
        }
    }

    // Rebuild the string from the stack
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int index = 0;
    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < count[i]; j++) {
            result[index++] = stack[i];
        }
    }
    result[index] = '\0';  // Null-terminate the result string
    
    return result;
}
