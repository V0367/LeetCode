// Last updated: 07/08/2026, 15:40:12
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) {
        return true;  // A list with 0 or 1 element is trivially a palindrome
    }

    // Step 1: Find the middle of the list using the slow and fast pointer approach
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct ListNode *prev = NULL, *current = slow, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Step 3: Compare the first and second halves of the list
    struct ListNode *firstHalf = head, *secondHalf = prev;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            return false;  // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;  // Palindrome
}
