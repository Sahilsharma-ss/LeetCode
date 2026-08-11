class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        int sum =nums[0];
        for(int  i =1;i<nums.size();i++)
        {
            if(nums[i-1]+1 == nums[i])
            {
                sum+=nums[i];
            }
            else
            {
                break;
            }
        }
        while(st.find(sum)!=st.end())
        {
            sum++;
        }
        return sum;
    }
};