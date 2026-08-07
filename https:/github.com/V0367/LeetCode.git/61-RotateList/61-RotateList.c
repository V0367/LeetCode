// Last updated: 07/08/2026, 15:40:26

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find the length of the list
    struct ListNode* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }

    // Step 2: Make the list circular
    current->next = head;

    // Step 3: Find the new head position
    k = k % length; // In case k is greater than the length of the list
    int stepsToNewHead = length - k;

    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 4: Break the circular connection and set the new head
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
