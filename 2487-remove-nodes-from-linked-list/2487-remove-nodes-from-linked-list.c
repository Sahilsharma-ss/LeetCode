/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL) {
        int data = curr->val;
        int flag = 0;
        struct ListNode *j = curr->next;

        while (j != NULL) {
            if (j->val > data) {
                flag = 1;
                break;
            }
            j = j->next;
        }

        if (flag == 1) {
            if (prev == NULL) {
                head = curr->next;
                free(curr);
                curr = head;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
