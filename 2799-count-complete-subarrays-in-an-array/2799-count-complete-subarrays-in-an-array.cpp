class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int>s(nums.begin(),nums.end());
        set<int>temp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                temp.insert(nums[j]);
                if(temp.size()==s.size())
                {
                    cnt++;
                }
            }
            temp.clear();
        }
        return cnt;
    }
};