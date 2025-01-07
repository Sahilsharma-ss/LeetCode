/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tail = headA;

        while(tail->next){
            tail = tail->next;
        }
        tail->next = headA;

        ListNode *fast = headB, *slow = headB;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) {
                slow = headB;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                tail->next = NULL;
                return slow;
            };
        }
        tail->next = NULL;
        return NULL;
    }
};