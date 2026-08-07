// Last updated: 07/08/2026, 15:40:37
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Check if the linked list is empty or if we don't need to reverse
    if (!head || k == 1) {
        return head;
    }

    // Function to reverse a part of the list
    struct ListNode* reverse(struct ListNode* start, struct ListNode* end) {
        struct ListNode* prev = NULL;
        struct ListNode* curr = start;
        struct ListNode* next = NULL;
        
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Dummy node to simplify the process
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* groupPrev = dummy;
    struct ListNode* groupEnd = head;

    // Traverse the linked list
    while (groupEnd) {
        // Move groupEnd to the end of the current k-group
        for (int i = 1; i < k && groupEnd; i++) {
            groupEnd = groupEnd->next;
        }

        // If we have a full k-sized group, reverse it
        if (groupEnd) {
            struct ListNode* groupStart = groupPrev->next;
            struct ListNode* nextGroup = groupEnd->next;
            
            // Break the group and reverse the part
            groupEnd->next = NULL;
            groupPrev->next = reverse(groupStart, NULL);
            groupStart->next = nextGroup;
            
            // Move the groupPrev and groupEnd pointers for the next round
            groupPrev = groupStart;
            groupEnd = groupPrev->next;
        }
    }
    
    return dummy->next;
}
