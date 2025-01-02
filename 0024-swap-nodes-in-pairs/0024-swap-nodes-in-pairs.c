/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *temp = head->next;
    struct ListNode *prev = NULL;  // To keep track of the previous node after a swap
    struct ListNode *new_head = temp;  // New head should be the second node (temp)
    
    while (head != NULL && head->next != NULL) {
        temp = head->next;  // The second node to be swapped

        // Perform the swap
        head->next = temp->next;
        temp->next = head;

        // If there was a previous pair, link it to the current swapped pair
        if (prev != NULL) {
            prev->next = temp;
        }

        // Update previous node and move head two steps forward
        prev = head;
        head = head->next;  // Move to the next pair
    }

    return new_head;  // Return the new head of the list
}
