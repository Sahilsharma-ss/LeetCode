class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(i-j)<=k && nums[j]==key)
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};