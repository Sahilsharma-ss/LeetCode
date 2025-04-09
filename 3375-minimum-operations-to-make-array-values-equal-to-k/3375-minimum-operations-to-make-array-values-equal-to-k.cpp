class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        if(*s.begin()<k) return -1;
        int c=0;
        for(auto i : s)
        {
            if(i>k)
            {
                c++;
            }
        }
        return c;
    }
};