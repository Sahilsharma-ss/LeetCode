class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool f=false;
        bool j=false;
        bool k=false;
        int n=nums.size();
        if(n<3) return false;
        int i=1;
            while(i<n&&(nums[i-1]<nums[i]))
                {
                    f=true;
                    i++;
                }
            while(i<n&&nums[i]<nums[i-1])
                {
                    j=true;
                    i++;
                }
            while(i<n && nums[i]>nums[i-1])
                {
                    k=true;
                    i++;
                }
        return f&&j&k&&i==n;
    }
};