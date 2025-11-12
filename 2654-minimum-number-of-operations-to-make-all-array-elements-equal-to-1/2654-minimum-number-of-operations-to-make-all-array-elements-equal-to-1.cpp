class Solution {
public:
    bool calculategcd(int st , int end , vector<int>&nums)
    {
        if(end-st+1==1) return  nums[st]==1;
        if(end-st+1==2)
        {
            return gcd(nums[st],nums[end])==1;
        }
        int g = gcd(nums[st],nums[st+1]);
        for(int i=st+2;i<=end;i++)
        {
            g = gcd(g,nums[i]);
        }
        return g==1;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool ok=false;
        int one=0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]==1)
            {
                one++;
            }
        }
        int mini = 1e9;
        if(one>0) return nums.size()-one;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(calculategcd(i,j,nums))
                {
                    mini = min(mini,j-i+1);
                }
            }
        }
        cout<<mini;
        if(mini == 1e9 ) return -1;
        return mini+nums.size()-2;
    }
};