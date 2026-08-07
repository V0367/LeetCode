// Last updated: 07/08/2026, 15:40:40
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Initialize pointers
    struct ListNode* newHead = head->next; // The second node becomes the new head
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    // Swap pairs iteratively
    while (current && current->next) {
        struct ListNode* nextPair = current->next->next; // Save the start of the next pair
        struct ListNode* second = current->next;

        // Swap the current pair
        second->next = current;
        current->next = nextPair;

        // Link the previous pair to the current swapped pair
        if (prev) {
            prev->next = second;
        }

        // Move to the next pair
        prev = current;
        current = nextPair;
    }

    return newHead;
}
