class Solution {
public:
    bool isvalid(int i,int j,int k,vector<int>&nums)
    {
        bool first=true;
        bool second=true;
        int len1=i+k;
        int len2=j+k;
        for(int s=i;s<len1-1;s++)
        {
            if(nums[s+1]<=nums[s])
            {
                first = false;
                break;
            }
        }
        for(int s=j;s<len2-1;s++)
        {
            if(nums[s+1]<=nums[s])
            {
                second=false;
                break;
            }
        }
        return first&&second;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(nums.size()==2 && k==1) return true;
        if(k>nums.size()) return false;
        int n=nums.size();
        for(int i=0;i<=n-2*k;i++)
        {
                int j=i+k;
                if(isvalid(i,j,k,nums))
                {
                    return true;
                }
        }
        return false;
    }
};