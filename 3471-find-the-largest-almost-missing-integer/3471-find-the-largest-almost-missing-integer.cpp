class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n =nums.size();
        if(n==1) return nums[0];
        int a = nums[0];
        int b = nums[n-1];
        unordered_map<int,int>mp;
         for(int i : nums)
        {
            mp[i]++;
        }
        if(k==1)
        {
           int maxi = -1e9;
           for(auto i : mp)
           {
                if(i.second==1)
                {
                    maxi = max(maxi,i.first);
                }
            }
            return maxi==-1e9?-1:maxi;
        }
        if(nums.size()==k)
        {
            return *max_element(nums.begin(),nums.end());
        }
        int cnt1=mp[a];
        int cnt2 =mp[b];
        
        if(cnt1==1 && cnt2==1)
        {
            return max(a,b);
        }
        if(cnt1==1)
        {
            return a;
        }
        if(cnt2==1)
        {
            return b;
        }
        return -1;
    }
};