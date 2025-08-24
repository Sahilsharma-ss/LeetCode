class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zcount=0;
        int max1=0;
        int start =0;
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0)
            {
                zcount++;
            }
            while(zcount>k)
            {
                if(nums[start]==0)
                {
                    zcount--;
                }
                start++;
            }
            max1 = max(max1,end-start+1);
        }
        return max1;
    }
};
