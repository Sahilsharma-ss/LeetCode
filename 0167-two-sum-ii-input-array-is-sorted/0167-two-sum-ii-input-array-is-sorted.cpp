class Solution {
public:
    int bs(vector<int>&nums,int tar)
    {
        int l = 0;
        int r =nums.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==tar) 
            {
                return mid;
            }
            else if(nums[mid]<tar)
            {
                l= mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>vec;
        int n = numbers.size();
        for(int i=0;i<n;i++)
        {
            int curr = numbers[i];
            int s = target-curr;
            if(i+1<n && s==numbers[i+1])
            {
                vec.push_back(i+1);
                vec.push_back(i+2);
                break;
            }
            int idx = bs(numbers,s);
            if(idx==-1) continue;
            if(idx>i)
            {
                vec.push_back(i+1);
                vec.push_back(idx+1);
                break;
            }
        }
        return vec;
    }
};