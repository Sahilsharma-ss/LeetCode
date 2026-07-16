class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        int n=nums.size();
        vector<int>p(n);
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,nums[i]);
            p[i] = gcd(nums[i],maxi);
        }
        sort(p.begin(),p.end(),greater<int>());
        long long ans = 0;
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            long long no = gcd(p[l],p[r]);
            ans+=no;
            l++;
            r--;
        }
        return ans;
    }
};