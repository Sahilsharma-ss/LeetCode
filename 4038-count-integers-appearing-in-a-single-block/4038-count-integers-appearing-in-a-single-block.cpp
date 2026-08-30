class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int cnt =0;
        for(auto i : mp)
        {
            vector<int>v=i.second;
            bool yes = true;
            for(int i=1;i<v.size();i++)
            {
                if(( v[i]-v[i-1] )!=1)
                {
                    yes = false;
                    break;
                }
            }
            if(yes) cnt++;
        }
        return cnt;
    }
};