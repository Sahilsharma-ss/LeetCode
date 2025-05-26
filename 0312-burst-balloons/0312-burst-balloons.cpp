class Solution {
public:
    int mcm(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        int maxi=-1e9;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int coins=nums[i-1]*nums[k]*nums[j+1] + mcm(i,k-1,nums,dp)+mcm(k+1,j,nums,dp);
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
      nums.insert(nums.begin()+0,1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return mcm(1,n-2,nums,dp);
    }
};