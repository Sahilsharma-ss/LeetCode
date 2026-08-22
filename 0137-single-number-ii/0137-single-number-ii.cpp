class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>vec(32,0);
        for(auto i : nums)
        {
            int ele = i;
            for(int mask=31;mask>=0;mask--)
            {
                if(ele &(1<<mask))
                {
                    vec[mask] = (vec[mask]+1)%3;
                }
            }
        }
        int no =0;
        for(int i=0;i<32;i++){
            if(vec[i])
            {
                no = no | (1<<i);
            }
        }
        return no;
    }
};