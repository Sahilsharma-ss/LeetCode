/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp = head;
        int cnt = 0 ;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        if(cnt==1)
        {
            return NULL;
        }
        if(cnt==2)
        {
            head->next=NULL;
            return head;
        }
        int mid = cnt/2;
        ListNode *t = head;
        mid= mid-1;
        while(mid--)
        {
            t= t->next;
        }
        t->next = t->next->next;
        // free(t->next);
        return head;
    }
};