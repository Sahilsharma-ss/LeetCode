class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorall =0;
        for(int i : nums)
        {
            xorall ^=i;
        }
        int xor1 = 0;
        int xor2 =0;
        int bit = xorall & (-xorall); // get the bit which is diffrent 
        for(int i : nums)
        {
            if(i & bit)
            {
                xor1^=i;
            }
            else
            {
                xor2^=i;
            }
        }
        return {xor1,xor2};
    }
};