class Solution {
public:
    // bool ismax(int st,int end,vector<int>&nums , int target)
    // {
    //     multiset<int>set;
    //         for(int i=st;i<=end;i++)
    //         {
    //             set.insert(nums[i]);
    //         }
    //    if(set.count(target)>(end-st+1)/2)
    //    {
    //        return true;
    //    }
    //     return false;
    // }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        vector<int> targetarr(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                cnt++;
            }
            targetarr[i] = cnt;
        }
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if ((targetarr[j] - (i > 0 ? targetarr[i - 1] : 0)) > ((j - i + 1) / 2)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};