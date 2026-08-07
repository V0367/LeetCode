// Last updated: 07/08/2026, 15:39:53
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    // Step 1: Create a prefix sum array
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;  // prefix[0] is 0 for convenience

    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // Step 2: Use a deque to track the indices of prefix sums
    // We will store indices in the deque, and try to find the shortest subarray
    int* deque = (int*)malloc((numsSize + 1) * sizeof(int));  // store indices of prefix sums
    int front = 0, rear = 0;  // initialize deque

    int minLength = INT_MAX;  // Variable to store the minimum length

    for (int i = 0; i <= numsSize; i++) {
        // Step 3: Remove elements from deque that don't form a valid subarray
        while (front < rear && prefix[i] - prefix[deque[front]] >= k) {
            minLength = (minLength < i - deque[front]) ? minLength : (i - deque[front]);
            front++;  // Pop from front of deque
        }

        // Step 4: Add the current index to the deque
        while (front < rear && prefix[i] <= prefix[deque[rear - 1]]) {
            rear--;  // Remove indices from the back of deque as they are no longer useful
        }
        deque[rear++] = i;  // Add current index to deque
    }

    free(prefix);
    free(deque);

    return minLength == INT_MAX ? -1 : minLength;
}
