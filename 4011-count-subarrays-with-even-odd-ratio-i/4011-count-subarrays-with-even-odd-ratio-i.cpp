class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        double ratio = (double)a/b;
        int n = nums.size();
       vector<int>even(n),odd(n);
       even[0] = nums[0]%2==0;
       odd[0] = nums[0]%2==1;
       int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                even[i] = even[i-1]+1;
            }
            else
            {
                even[i] = even[i-1];
            }
            if(nums[i]%2==1)
            {
                odd[i] = odd[i-1]+1;
            }
            else
            {
                odd[i] = odd[i-1];
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j =i;j<n;j++)
            {
                int ev = even[j] - (((i-1)>=0)?even[i-1]:0);
                int od = odd[j] - (((i-1)>=0)?odd[i-1]:0);
                if(od>0)
                {
                    if(((double)ev/(double)od) <= ratio)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};