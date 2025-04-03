class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        int currmax=nums[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=currmax;
            currmax=max(currmax,nums[i]);
           
        }
        int rmax=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=rmax;
            rmax=max(rmax,nums[i]);
        }
        long long res=0;
        for(int i=0;i<n;i++)
        {
            long long s=(long long)(leftmax[i]-nums[i])*rightmax[i];
            res=max(res,s);
        }
        return res;
    }
};