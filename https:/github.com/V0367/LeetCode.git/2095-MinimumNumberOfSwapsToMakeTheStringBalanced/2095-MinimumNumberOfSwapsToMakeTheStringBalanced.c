// Last updated: 07/08/2026, 15:39:24
int minSwaps(char* s) {
    int balance = 0;  // Keeps track of the balance of '[' and ']'
    int swaps = 0;    // Counter for required swaps
    
    // Traverse the string to track the balance and count necessary swaps
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            balance++;  // Increase balance for '['
        } else {
            balance--;  // Decrease balance for ']'
        }

        // If the balance is negative, we have an imbalance that requires a swap
        if (balance < 0) {
            swaps++;
            balance = 1;  // Reset balance to 1 after fixing the imbalance
        }
    }

    return swaps;
}
