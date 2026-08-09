class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int>pref(n),suff(n);
        // pref[0] = nums[0];
        // for(int i=1;i<nums.size();i++)
        // {
        //     pref[i] = pref[i-1]*nums[i];
        // }
        // suff[n-1] = nums[n-1];
        // for(int i=n-2;i>=0;i--)
        // {
        //     suff[i] = suff[i+1]*nums[i];
        // }

        // vector<int>ans;
        // for(int i =0;i<n;i++) //   1 2 3 4 
        // {
        //     int left = (i-1)>=0?pref[i-1]:1;
        //     int right = (i+1)<n?suff[i+1]:1;
        //     ans.push_back(left*right);
        // }

        int zero = 0;
        int mul = 1;
        int ind = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]==0)
            {
                ind = i;
                zero++;
                continue;
            }
            mul*=nums[i];
        }
        vector<int>ans(n,0);
        if(zero>=2)
        {
            return ans;
        }
        else if(zero==1)
        {
            ans[ind] = mul;
            return ans;
        }
        for(int i =0;i<n;i++)
        {
            ans[i] = mul/nums[i];
        }
        return ans;
    }
};