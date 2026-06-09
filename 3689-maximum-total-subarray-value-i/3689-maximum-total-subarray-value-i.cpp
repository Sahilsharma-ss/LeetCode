typedef long long ll;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll  min= *min_element(nums.begin(),nums.end());
        ll  max= *max_element(nums.begin(),nums.end());
        ll diff = max-min;
        return (ll) diff*k;

    }
};