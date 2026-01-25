class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>neg;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                neg.push_back(nums[i]);
                nums[i] = -1e9;
            }
        }
        if(neg.size()==0) return nums;
        int pos = 0;
        while(k)
        {
            pos = (pos+1)%neg.size();
            k--;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==-1e9)
            {
                nums[i] = neg[pos];
                pos = (pos+1)%neg.size();
            }
        }
        return nums;
    }
};