class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>preSum(n,0);
        deque<int>dq;
        int res = 1e9;
        int j=0;
        while(j<n)
        {
            if(j==0)
            {
                preSum[j] = nums[j];
            }
            else
            {
                preSum[j] = preSum[j-1]+nums[j];
            }

            if(preSum[j]>=k)
            {
                res = min(res,j+1);
            }

            while(!dq.empty() && preSum[j] - preSum[dq.front()] >= k)
            {
                res = min(res,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && preSum[j] <= preSum[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return res==1e9?-1:res;
    }
};