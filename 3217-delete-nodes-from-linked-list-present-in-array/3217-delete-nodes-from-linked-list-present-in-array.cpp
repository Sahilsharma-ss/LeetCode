class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        while (head && st.find(head->val) != st.end()) {
            head = head->next;
        }

        if (!head) return nullptr;

        ListNode* temp = head;
        while (temp && temp->next) {
            if (st.find(temp->next->val) != st.end()) {
                temp->next = temp->next->next;  
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
