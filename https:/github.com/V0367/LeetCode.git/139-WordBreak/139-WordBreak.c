// Last updated: 07/08/2026, 15:40:15
#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    // Iterate through the string
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                for (int k = 0; k < wordDictSize; k++) {
                    int wordLen = strlen(wordDict[k]);
                    if (i - j == wordLen && strncmp(s + j, wordDict[k], wordLen) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break;
        }
    }

    return dp[len];
}
