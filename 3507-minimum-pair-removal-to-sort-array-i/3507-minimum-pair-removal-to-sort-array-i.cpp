class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        vector<int>temp3(nums.begin(),nums.end());
        sort(temp3.begin(),temp3.end());
        if(temp3==nums) return 0;
        while(nums.size()>1)
        {
            int idx =0;
            int mini = 1e9;
            for(int i=1;i<nums.size();i++)
            {
                int sum = nums[i-1]+nums[i];
                if(sum<mini)
                {
                    mini = sum;
                    idx =i;
                }
            }
            vector<int>temp;
            for(int i=0;i<nums.size();i++)
            {
                if(i!=idx-1 && i!=idx)
                {
                    temp.push_back(nums[i]);
                }
            }
            temp.insert(temp.begin()+(idx-1),(nums[idx-1]+nums[idx]));
            vector<int>temp2(temp.begin(),temp.end());
            sort(temp2.begin(),temp2.end());
            cnt++;
            if(temp==temp2)
            {
                return cnt;
            }
            nums = temp;
        }
        return 0;
    }
};