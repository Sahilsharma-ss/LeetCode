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
 typedef pair<int,ListNode*> p;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)  return NULL;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto i : lists)
        {
            if(i)
            {
                pq.push({i->val,i});
            }
        }
        ListNode dummy; // create actual object 
        ListNode* head = &dummy; // only pointer pointing dummy 
        while(!pq.empty())
        {
            auto i = pq.top();
            pq.pop();
            head->next = i.second;
            head = head->next;
           if(i.second->next) pq.push({i.second->next->val,i.second->next});
        }
        return dummy.next;
    }
};