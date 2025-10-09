class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i =n-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(i==j) continue;
                int k=0;
                int l=j-1;
                while(k<l)
                {
                    long long sum =(long long) nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        vector<int>vec{nums[i],nums[j],nums[k],nums[l]};
                        sort(vec.begin(),vec.end());
                        st.insert(vec);
                    }
                    if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
                
            }
        }
        vector<vector<int>>res;
        for(auto i : st)
        {
            res.push_back(i);
        }
        return res;
    }
};