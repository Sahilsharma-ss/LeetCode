class Solution {
public:
    int productwithoutzero(vector<int>&nums)
    {
        int prod=1;
        for(auto i : nums)
        {
            if(i!=0)
            {
                prod*=i;
            }
        }
        return prod;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int n=nums.size();
        bool zero=false;
        int zerocnt=0;
        vector<int>haszero(n,0);
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            if(nums[i]==0)
            {
                zero=true;
                haszero[i]=1;
                zerocnt++;
            }
        }
        vector<int>res(n,0);
        if(!zero)
        {
            for(int i=0;i<n;i++)
            {
                res[i]=prod/nums[i];
            }
        }
        else if(zerocnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(haszero[i]==1)
                {
                    res[i]=productwithoutzero(nums);
                }
            }
        }
        return res;
    }
};