// Last updated: 07/08/2026, 15:39:22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    // Result array to store the operations
    char** operations = (char**)malloc(2 * n * sizeof(char*));
    int opIndex = 0;  // Keeps track of the number of operations performed
    int targetIndex = 0;  // Keeps track of position in the target array

    // Loop through the integers from 1 to n
    for (int num = 1; num <= n; num++) {
        // "Push" operation
        operations[opIndex] = (char*)malloc(5 * sizeof(char));
        strcpy(operations[opIndex], "Push");
        opIndex++;

        // If the current number matches the target, pop it from the stack
        if (targetIndex < targetSize && num == target[targetIndex]) {
            targetIndex++;  // Move to next element in the target
        } else {
            // If not matching, we "Pop" the top element from the stack
            operations[opIndex] = (char*)malloc(4 * sizeof(char));
            strcpy(operations[opIndex], "Pop");
            opIndex++;
        }

        // If we've matched the entire target, stop further operations
        if (targetIndex == targetSize) {
            break;
        }
    }

    // Return the operations and the number of operations performed
    *returnSize = opIndex;
    return operations;
}
