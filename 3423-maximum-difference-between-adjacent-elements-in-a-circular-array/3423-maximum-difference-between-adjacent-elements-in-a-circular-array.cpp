class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int a=nums[0];
        int c=nums[nums.size()-1];
        int maxi=-1e9;
        for(int i=1;i<nums.size();i++)
        {
            maxi=max(maxi,abs(nums[i-1]-nums[i]));
        }
        return max(maxi,abs(c-a));
    }
};