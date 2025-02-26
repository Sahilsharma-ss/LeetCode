class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totals=0,maxs=INT_MIN,mins=INT_MAX;
        int n=nums.size();
        int currmax=0,currmin=0;
        for(auto i : nums)
        {
            totals +=i;
            currmax= max(i,currmax+i);
            maxs = max(maxs,currmax);
            currmin=min(i,currmin+i);
            mins =min(mins,currmin);
        }
        if(totals-mins==0) return maxs;
        return max(maxs,totals-mins);
    }
};