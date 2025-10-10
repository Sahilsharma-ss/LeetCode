class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int read=0;
        int write=0;
        int n=nums.size();
        while(read<n)
        {
            if(nums[read]!=val)
            {
                nums[write]=nums[read];
                write++;
            }
            read++;
        }
        return write;
    }
};