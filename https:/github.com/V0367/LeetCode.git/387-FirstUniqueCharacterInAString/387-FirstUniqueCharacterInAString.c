// Last updated: 07/08/2026, 15:40:09
int firstUniqChar(char* s) {
    int freq[26] = {0};  // Array to store the frequency of each character
    
    // First pass: count the frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    
    // Second pass: find the first character with a frequency of 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;  // Return the index of the first unique character
        }
    }
    
    return -1;  // No unique character found
}
