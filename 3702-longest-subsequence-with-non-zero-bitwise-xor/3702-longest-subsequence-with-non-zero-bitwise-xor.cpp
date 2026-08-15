class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int tot=0;
        bool allzero=true;
        for(auto i : nums)
            {
                tot^=i;
                if(i!=0)
                {
                    allzero=false;
                }
            }
        if(allzero) return 0;
        if(tot!=0) return n;
        for(int x :nums)
            {
                if((tot^x)!=0)
                {
                    return n-1;
                }
            }
        return 0;
    }
};