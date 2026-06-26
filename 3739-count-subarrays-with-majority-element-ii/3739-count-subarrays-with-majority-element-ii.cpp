class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //Instead of map you can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)
        unordered_map<int,int> mp;   // mp[cumSum] = frequency of how many times cumSum has occurred
        
        int currSum = 0;
        
        mp[0] = 1; 

        long long validLeftPoints = 0;

        long long result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};