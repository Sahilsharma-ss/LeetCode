class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>count(101,0);
        vector<int>ans;
        for(auto i : nums)
        {
            count[i]++;
        }
        for(int i=1 ;i<101;i++)
        {
            count[i]+=count[i-1];
        }
        for(int i : nums)
        {
            if(i==0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(count[i-1]);
            }
        }
        return ans;
    }
};