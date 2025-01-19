

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int pairSum(struct ListNode* head) {
    int sum=0;
    int maxs=0;
    int count=0;
    struct ListNode *temp =head;
    struct ListNode *slow =head;
    struct ListNode *fast =head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow =slow->next;
        fast=fast->next->next;
    }
     struct ListNode *prev =NULL;
    struct ListNode *curr =slow;
    struct ListNode *next =NULL;
    while(curr!=NULL)
    {
        next =curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(head!=NULL&&prev!=NULL)
    {
        sum = head->val+prev->val;
        maxs= maxs>sum?maxs:sum;
        head=head->next;
        prev=prev->next;
    }
    return maxs;
} 