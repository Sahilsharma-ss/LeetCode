class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        stack<int> stk;
        stk.push(0);   

        for (int num : nums) {
            while (!stk.empty() && stk.top() > num) {
                stk.pop();
            }
            if (stk.top() < num) {
                cnt++;
                stk.push(num);
            }
        }

        return cnt;
    }
};
