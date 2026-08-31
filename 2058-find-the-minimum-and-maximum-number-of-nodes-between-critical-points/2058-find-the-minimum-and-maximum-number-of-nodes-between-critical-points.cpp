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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = head->val;
        head = head->next;
        vector<int>ans;
        int cnt = 2;
        while(head->next!=NULL)
        {
            if(head->val > prev && head->val>head->next->val || head->val<prev && head->val < head->next->val)
            {
                ans.push_back(cnt);
            }
            cnt++;
            prev=head->val;
            head = head->next;
        }
        if(ans.size()<2) return {-1,-1};
        int mini =1e9;
        int n = ans.size();
        for(int i=1;i<n;i++)
        {
            mini  = min(mini,ans[i]-ans[i-1]);
        }
        return {mini,ans[n-1]-ans[0]};   
    }
};