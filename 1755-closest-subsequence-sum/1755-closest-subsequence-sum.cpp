class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n / 2;  // 1st array size
        int n2 = n - n1; // 2nd array size
        // cout<<n1<<" "<<n2;
        vector<int> sum1, sum2;
        for (int mask = 0; mask < (1 << n1); mask++) // 0 - 2^n-1
        {
            int sum = 0;
            for (int i = 0; i < n1; i++) // 1st half
            {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            sum1.push_back(sum);
        }
        for (int mask = 0; mask < (1 << n2); mask++) // 0 - 2^n-1
        {
            int sum = 0;
            for (int i = 0; i < n2; i++) // 1st half
            {
                if (mask & (1 << i)) {
                    sum += nums[i + n1];
                }
            }
            sum2.push_back(sum);
        }
        // for(auto i : sum1)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i : sum2)
        // {
        //     cout<<i<<" ";
        // }
        sort(sum2.begin(), sum2.end());
        int ans = 1e9;
        int sz1 = sum1.size();
        int sz2 = sum2.size();
        for (int i = 0; i < sz1; i++) {
            int target = goal - sum1[i];
            // cout<<" tar is : "<<target<<endl;
            auto it = lower_bound(sum2.begin(), sum2.end(), target);

            if (it != sum2.end())
                ans = min(ans, abs(target - *it));

            if (it != sum2.begin()) {
                --it;
                ans = min(ans, abs(target - *it));
            }
        }
        return ans;
    }
};