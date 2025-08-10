class Solution {
public:

    int sortPermutation(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        if (nums == sorted) {
            return 0;
        }
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(i);
        }
        if (nums[0] != vec[0]) {
            return 0;
        }
        vector<int>vec2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != vec[i]) {
                vec2.push_back(nums[i]);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<vec2.size();i++)
        {
            for(int j=0;j<vec2.size();j++)
            {
                if(i!=j)
                {
                    mini=min(mini,vec2[i]&vec2[j]);
                }
            }
        }

        return mini;
    }
    };