#include<algorithm>
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>answer;
        int leftsum=0,rightsum=0;
        int sum=0;
        int sumr=std::accumulate(nums.begin(),nums.end(),0);
        rightsum=sumr;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                leftsum=0;
            }
            else
            {
                leftsum=leftsum+nums[i-1];
            }
            rightsum=rightsum-nums[i];
            sum=abs(leftsum-rightsum);
            answer.push_back(sum);
        }
        return answer;
    }
};