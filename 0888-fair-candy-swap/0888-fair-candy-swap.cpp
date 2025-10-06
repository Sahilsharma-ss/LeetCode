class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int total_a = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int total_b = accumulate(bobSizes.begin(),bobSizes.end(),0);
        vector<int>vec(2,0);
       for(int i=0;i<aliceSizes.size();i++)
       {
        for(int j=0;j<bobSizes.size();j++)
        {
            int temp1 = total_a-aliceSizes[i]+bobSizes[j];
            int temp2= total_b+aliceSizes[i]-bobSizes[j];
            if(temp1==temp2)
            {
                vec[0] = aliceSizes[i];
                vec[1]=bobSizes[j];
                break;
            }
        }
       }
       return vec;
    }
};