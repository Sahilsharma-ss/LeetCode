class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int rob=0;
        int norob=0;
        for(int i=0;i<n;i++)
        {
            int newrob = norob +nums[i];
            int nonewrob = max(norob,rob);
            rob=newrob;
            norob=nonewrob;
        }
        return max(rob,norob);
    }
};