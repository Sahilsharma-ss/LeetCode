class Solution {
public:
    int solve(unordered_map<int,int>mp,int x)
    {
        vector<pair<int,int>>vec;
        for(auto i: mp)
        {
            vec.push_back({i.second,i.first});
        }
        sort(vec.begin(),vec.end(),[&](auto const &a ,auto const &b)
        {
            if(a.first != b.first)
            {
                return a.first>b.first;
            }
            return a.second>b.second;
        });
        int sum=0;
        int sz=vec.size();
        int end = min(x,sz);
        for(int i =0 ;i<end; i++)
        {
            sum += vec[i].first * vec[i].second;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int l=0,r=0;
        vector<int>res(n-k+1);
        int ind=0;
        while(r<n)
        {
            mp[nums[r]]++;
            if(r-l+1>k)
            {
                mp[nums[l]]--;
                l++;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
            }
            if(r-l+1==k)
            {
                res[ind++] = solve(mp,x);
            }
            r++;
        }
        return res;
    }
};