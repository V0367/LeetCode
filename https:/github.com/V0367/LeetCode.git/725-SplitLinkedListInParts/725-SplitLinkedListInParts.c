// Last updated: 07/08/2026, 15:40:07
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // Step 1: Find the total length of the linked list.
    int len = 0;
    struct ListNode* temp = head;
    while (temp) {
        len++;
        temp = temp->next;
    }
    
    // Step 2: Calculate the base size and extra nodes.
    int part_size = len / k;
    int extra_parts = len % k;
    
    // Step 3: Create an array to store the parts.
    struct ListNode** parts = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    
    // Step 4: Split the list into parts.
    temp = head;
    for (int i = 0; i < k; i++) {
        struct ListNode* part_head = temp;
        int current_part_size = part_size + (i < extra_parts ? 1 : 0);
        
        // Traverse the part_size nodes for the current part.
        for (int j = 0; j < current_part_size - 1; j++) {
            if (temp) temp = temp->next;
        }
        
        // Disconnect the current part if it's not the last node.
        if (temp) {
            struct ListNode* next = temp->next;
            temp->next = NULL;
            temp = next;
        }
        
        parts[i] = part_head;
    }
    
    *returnSize = k;
    return parts;
}
