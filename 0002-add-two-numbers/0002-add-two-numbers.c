/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node to serve as the head of the result list.
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode *curr = dummy;
    int carry = 0;
    
    // Iterate through both linked lists until both are exhausted and no carry is left.
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;
        
        // Add value from l1 if available
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add value from l2 if available
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Add any carry from the previous operation
        sum += carry;
        carry = sum / 10;  // Update carry
        
        // Create a new node for the current digit
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        
        // Append the new node to the result list
        curr->next = node;
        curr = curr->next;
    }
    
    // Return the next of dummy since dummy is a placeholder.
    struct ListNode *result = dummy->next;
    free(dummy); // Free the dummy head node
    return result;
}