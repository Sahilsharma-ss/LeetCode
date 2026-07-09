class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // vector<bool>ans(n,false);
        vector<bool>res;
        // for(int i =1;i<n;i++)
        // {
        //     if(abs(nums[i-1]-nums[i])<=maxDiff)
        //     {
        //         ans[i] = true;
        //         ans[i-1] = true;
        //     }
        //     else
        //     {
        //         ans[i-1] = false;
        //     }
        // }
        unordered_map<int,int>mp;
        for(auto i : nums)
        {
            mp[i] = i;
        }
         for(int i =1;i<n;i++)
        {
            if(abs(nums[i-1]-nums[i])<=maxDiff)
            {
               mp[nums[i]] = mp[nums[i-1]];
            }
        }
        for(auto i : queries )
        {
            if( (mp[nums[i[0]]] == mp[nums[i[1]]] ) || (i[0]==i[1]))
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};