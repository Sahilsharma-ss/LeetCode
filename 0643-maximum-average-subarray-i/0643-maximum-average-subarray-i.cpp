#include<numeric>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res;
        int sum =0;
        for(int i =0 ; i<k; i++)
        {
            sum+=nums[i];
        }
        int maxs=sum;
        int start = 0;
        int end =k;
        while(end < nums.size())
        {
            sum-=nums[start];
            start++;
            sum+=nums[end];
            end++;
            maxs= max(sum,maxs);
        }
        res= maxs/(double)k;
        return res;
    }
};