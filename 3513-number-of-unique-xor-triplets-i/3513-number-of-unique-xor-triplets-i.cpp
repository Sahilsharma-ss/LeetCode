class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 1;
        if(n<=2) return 2;
        int ans = 2;
        while(ans<=n)
        {
            ans*=2;
        }
        return ans;
    }
};