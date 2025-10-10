class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write=0;
        int read=0;
        int n=nums.size();
        while(read<n)
        {
            if(nums[read]!=nums[write])
            {
                write++;
                nums[write]=nums[read];
                
            }
            read++;
        }
        return write+1;
    }
};