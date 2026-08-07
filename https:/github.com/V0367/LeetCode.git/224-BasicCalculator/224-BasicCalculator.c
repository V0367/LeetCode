// Last updated: 07/08/2026, 15:40:10
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    int result = 0, sign = 1, currentNumber = 0;
    int stack[1000], stackTop = -1;
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) {
            // Build the current number
            currentNumber = currentNumber * 10 + (s[i] - '0');
        } else if (s[i] == '+') {
            result += sign * currentNumber;
            sign = 1; // Set sign to positive for next number
            currentNumber = 0;
        } else if (s[i] == '-') {
            result += sign * currentNumber;
            sign = -1; // Set sign to negative for next number
            currentNumber = 0;
        } else if (s[i] == '(') {
            // Push the result and sign onto the stack for handling nested expressions
            stack[++stackTop] = result;
            stack[++stackTop] = sign;
            result = 0; // Reset result for the current sub-expression
            sign = 1;   // Reset sign to positive for the sub-expression
        } else if (s[i] == ')') {
            // Apply the result of the current sub-expression
            result += sign * currentNumber;
            currentNumber = 0;
            result *= stack[stackTop--]; // Multiply by the sign before the parenthesis
            result += stack[stackTop--]; // Add the result before the parenthesis
        }
    }
    
    // Final addition of the last number
    result += sign * currentNumber;
    
    return result;
}
