class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,sum=0,minlen=1e9;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>target)
            {
                sum-=nums[l];
                l++;
            }
            if(sum>=target)
            {
                int len=r-l+1;
                minlen=min(minlen,len);
            }
            r++;
        }
        if(minlen==1e9) return 0;
        return minlen;
    }

};