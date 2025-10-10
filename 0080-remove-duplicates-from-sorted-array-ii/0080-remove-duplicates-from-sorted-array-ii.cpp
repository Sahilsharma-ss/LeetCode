class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int read = 2;
        int write = 2;
        while(read < n)
        {
            if(nums[read] != nums[write - 2])
            {
                nums[write] = nums[read];
                write++;
            }
            read++;
        }
        return write;
    }
};
