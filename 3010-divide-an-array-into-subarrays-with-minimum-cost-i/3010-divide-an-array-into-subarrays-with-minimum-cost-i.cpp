class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n= nums.size();
        vector<pair<int,int>>vec;
        for(int i=1;i<nums.size();i++)
        {
            vec.push_back({nums[i],i});
        }
        if(nums.size()==3)
        {
            return accumulate(nums.begin(),nums.end(),0);
        }
        sort(vec.begin(),vec.end());
        int prev = 0;
        int ans = nums[0];
        int cnt = 1;
        for(auto i : vec)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i : vec)
        {
            int ele = i.first;
            int ind = i.second;
                ans+=ele;
               // prev = ind;
                cnt++;
            if(cnt==3) break;
        }
        return ans;
    }
};