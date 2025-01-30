
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *res = NULL, *res1 = NULL;
    head = head->next;
    
    while (head != NULL) {
        int sum = 0;
        while (head != NULL && head->val != 0) {
            sum += head->val;
            head = head->next;
        }

        // Create a new node with the sum
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum;
        temp->next = NULL;
        
        if (res == NULL) {
            res = res1 = temp;
        } else {
            res1->next = temp;
            res1 = temp;
        }

        if (head != NULL) {
            head = head->next; // Move to the next node after zero
        }
    }
    return res;
}
